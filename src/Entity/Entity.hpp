#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <typeinfo>

namespace nty
{   
    template<typename T> std::vector<T> & getList()
    {
        static std::vector<T> List;
        return List;
    }
    
    class Entity 
    {
        private:
            struct p_Component
            {
                p_Component(const std::type_info* type, int index) : m_index(index), m_type(type->name()) {}
                const int m_index;
                const std::string m_type;
                template <typename T> T& get(){ return getList<T>()[m_index]; }
            };

            std::vector<p_Component> m_components;
            
            template <typename T> p_Component getComp()
            {
                for (auto & component : m_components)
                {
                    if (component.m_type == typeid(T).name()) return component;
                }
                
                getList<T>().push_back(T());
                p_Component component(&typeid(T), getList<T>().size() - 1);
                m_components.push_back(component);
                return component;
            }

        public:
            template <typename T>
            struct Component
            {
                public:
                    Component(p_Component p_c) : p_comp(p_c) {}
                    T& get() { return p_comp.get<T>(); }
                private:
                    p_Component p_comp;
            };

            template <typename T> T& get()
            {
                p_Component component = getComp<T>();
                return component.get<T>();
            }

            template <typename T> Component<T> getComponent()
            {
                return Component<T>(getComp<T>());
            }
    };

    template <typename T>
    using Component = Entity::Component<T>;

}