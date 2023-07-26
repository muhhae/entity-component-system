#include <iostream>

#include "Entity/Entity.hpp"
#include "Component/Transform.hpp"

struct ComponentThatDoesntExist
{
    
};

void checkEntity()
{
    nty::Entity gameObject;
    //Add component to the entity
    gameObject.add<Transform>();
    gameObject.add<Color>();
    gameObject.add<ClassColor>();

    /*  getComponent<T> return a Component<T> 
        that store index and type of the component, so you can get the component with Component<T>.get() or getOther<T>()
        get() return a reference to the component getOther<T>() return a reference to other component 
        that belong to the same entity */

    /*  you can also use gameObject.get<T>() that return a reference to actual component
        but don't store it as reference because it can be deallocated if the component is moved through memory
        just use getComponent<T> if you really need to store it as reference */

    /*  component.get() and component.getOther<T>() and gameObject.get<T>() 
        throw an exception if the component doesn't exist
        you should use gameObject.exist<T>() to check if the component exist 
        or use Try() catch() to catch the exception */

    nty::Component<Transform> transform = gameObject.getComponent<Transform>();
    nty::Component<Color> color = gameObject.getComponent<Color>();
    nty::Component<ClassColor> classColor = gameObject.getComponent<ClassColor>();

    std::cout << "Transform : " << transform.get().x << " " << transform.get().y << " " << transform.get().z << std::endl;
    std::cout << "Color : "<< color.get().name << std::endl;
    std::cout << "ClassColor : "; classColor.get().print(); std::cout << std::endl;

    std::cout << "Changing their values..." << std::endl;

    transform.get().x = 1;
    transform.get().y = 2;
    transform.get().z = 3;

    color.get().name = "blue";
    classColor.get().setColor({"green"});

    std::cout << "Transform : " << transform.get().x << " " << transform.get().y << " " << transform.get().z << std::endl;
    std::cout << "Color : "<< color.get().name << std::endl;
    std::cout << "ClassColor : "; classColor.get().print(); std::cout << std::endl;

    std::cout << "Trying to get a component that doesn't exist..." << std::endl;

    //this is fine, but gonna crash the program if you try to access the component
    nty::Component<ComponentThatDoesntExist> notExist = gameObject.getComponent<ComponentThatDoesntExist>(); 
    //crash the program
    // gameObject.get<ComponentThatDoesntExist>();
    //also crash the program
    // notExist.get();

    //solution check if the component exist before getting it
    if (gameObject.exist<ComponentThatDoesntExist>()) gameObject.get<ComponentThatDoesntExist>();
    else std::cout << "ComponentThatDoesntExist doesn't exist" << std::endl;

    //or use try catch
    try
    {
        gameObject.get<ComponentThatDoesntExist>();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //or use try catch with the component
    try
    {
        notExist.get();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //Add component that you need before using them, if component exist it will not be created, so it's safe to use
    gameObject.add<ComponentThatDoesntExist>();
    //now you can use it
    if (gameObject.exist<ComponentThatDoesntExist>()) 
    {
        gameObject.get<ComponentThatDoesntExist>();
        std::cout << "ComponentThatDoesntExist exist" << std::endl;
    }
    else std::cout << "ComponentThatDoesntExist doesn't exist" << std::endl;

    //or use try catch
    try
    {
        gameObject.get<ComponentThatDoesntExist>();
        std::cout << "ComponentThatDoesntExist exist" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //or use try catch with the component
    try
    {
        notExist.get();
        std::cout << "ComponentThatDoesntExist exist" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main()
{
    checkEntity();
    return 0;
}