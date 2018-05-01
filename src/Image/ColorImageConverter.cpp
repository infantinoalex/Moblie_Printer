#include "ColorImageConverter.hpp"
#include "Colors.hpp"
#include "../Helper.cpp"

#include <stdexcept>
#include <kipr/botball.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iostream>

ColorImageConverter::ColorImageConverter()
{
}

ColorImageConverter::ColorImageConverter(std::map<Colors, Image> colorImages)
{
    int colorChannelsArray[] = { (int)Blue, (int)Red, (int)Yellow, (int)Green };

    this->_colorChannels = std::vector<int>(colorChannelsArray, colorChannelsArray + sizeof(colorChannelsArray) / sizeof(colorChannelsArray[0]));
    this->_colorImages = colorImages;
}

Image ColorImageConverter::GrabAndConvertImage()
{
    int loops = 0;
    while(true)
    {
        if (loops > 2000)
        {
            camera_close();

            throw std::runtime_error("Camera could not find image in alloted time.");
        }

        int i;
        int numberOfChannels = sizeof(this->_colorChannels) / sizeof(this->_colorChannels[0]);
       
        camera_open();
	
	    std::cout << "Number of color channels" << numberOfChannels << std::endl;

        for (i = 0; i < numberOfChannels; ++i)
	    {
            while(!camera_update());

            if (get_object_count(this->_colorChannels[i]))
            {
                camera_close();

                std::cout << "Found color " << ConvertColorToString(i) << "on screen. Converting to image." << std::endl;

		        Colors colorValue = static_cast<Colors>(i);
                return this->_colorImages[colorValue];
            }
        }

	    msleep(100);
        loops++;
    }
}
