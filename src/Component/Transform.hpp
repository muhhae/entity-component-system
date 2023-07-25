#pragma once

#include <iostream>

struct Transform
{
    float x, y, z;
};

struct Color
{
    std::string name;
};

class ClassColor
{
    public :
        void print()
        {
            std::cout << "Color : " << m_color.name << std::endl;
        }
        void setColor(Color color) 
        {
            m_color = color;
        }
    private :
        Color m_color = {"red"};
};