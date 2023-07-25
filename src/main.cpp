#include <iostream>

#include "Entity/Entity.hpp"
#include "Component/Transform.hpp"

void checkEntity()
{
    nty::Entity gameObject;
    gameObject.get<Transform>() = {9, 7, 8};
    gameObject.get<Transform>().x = 10;
    gameObject.get<Color>().name = "Blue";

    nty::Component<Transform> transform = gameObject.getComponent<Transform>();

    transform.get().x = 100;

    std::cout << gameObject.get<Transform>().x << " " << gameObject.get<Transform>().y << " " << gameObject.get<Transform>().z << std::endl;
    std::cout << gameObject.get<Color>().name << std::endl;

    transform.get().x = 1000;
    transform.getOther<Color>().name = "Red";

    std::cout << gameObject.get<Transform>().x << " " << gameObject.get<Transform>().y << " " << gameObject.get<Transform>().z << std::endl;
    std::cout << gameObject.get<Color>().name << std::endl;
    std::cout << "col class = ";

    gameObject.getComponent<Transform>().getOther<ClassColor>().print();
    transform.getOther<ClassColor>().setColor({"Orange"});
    std::cout << "col class = ";
    gameObject.getComponent<Transform>().getOther<ClassColor>().print();
}

int main()
{
    checkEntity();

    return 0;
}