// #include "Entity.hpp"

// namespace nty 
// {   
//     template<typename T> Component Entity::getComponent()
//     {
//         for (auto & component : m_components)
//         {
//             if (component.m_type == typeid(T).name()) return component;
//         }
        
//         getList<T>().push_back(T());
//         Component component(typeid(T), getList<T>().size() - 1);
//         m_components.push_back(component);
//         return component;
//     }

//     template <typename T> T & Entity::get()
//     {
//         Component component = getComponent<T>();
//         return component.get<T>();
//     }
// }