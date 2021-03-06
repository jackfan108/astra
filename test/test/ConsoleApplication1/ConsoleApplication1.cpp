// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <astra/astra.hpp>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <cstdio>
#include <iostream>

int main(int argc, char** argv)
{
	astra::initialize();

	std::cout << "after init" << std::endl;

	astra::StreamSet streamSet;
	astra::StreamReader reader = streamSet.create_reader();
	std::cout << "reader created" << std::endl;


	reader.stream<astra::DepthStream>().start();
	std::cout << "depth stream started" << std::endl;

	const int maxFramesToProcess = 100;
	int count = 0;
	do {
		astra::Frame frame = reader.get_latest_frame();
		// std::cout << "last frame gotten" << std::endl;

		const auto depthFrame = frame.get<astra::DepthFrame>();
		// std::cout << "depth frame gotten" << std::endl;
		const int frameIndex = depthFrame.frame_index();
		const short pixelValue = depthFrame.data()[300];
		// std::cout << "pixel :D" << std::endl;

		std::cout << std::endl
			<< "Depth frameIndex: " << frameIndex
			<< " pixelValue: " << pixelValue
			<< std::endl
			<< std::endl;

        count++;

	} while (count < maxFramesToProcess);




	astra::terminate();

	std::cout << "hit enter to exit program" << std::endl;
	std::cin.get();

	return 0;
}