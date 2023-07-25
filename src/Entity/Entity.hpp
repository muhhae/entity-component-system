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
                public:
                    p_Component(const std::type_info* type, int index) : m_index(index), m_type(type->name()) {}
                    const int m_index;
                    const std::string m_type;
                    template <typename T> T& get() { return getList<T>()[m_index]; }
                private:
                    Entity* m_entity;

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
                    Component(Entity* parent) : m_parent(parent) {}
                    T& get() { return m_parent->get<T>(); }
                    template <typename U> U& getOther() { return m_parent->get<U>(); }
                private:
                    Entity* m_parent;
            };

            template <typename T> T& get()
            {
                p_Component component = getComp<T>();
                return component.get<T>();
            }

            template <typename T> Component<T> getComponent()
            {
                return Component<T>(this);
            }
    };

    template <typename T>
    using Component = Entity::Component<T>;
}