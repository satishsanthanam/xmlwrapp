
// standard includes
#include <iostream>
#include <fstream>
#include <exception>
#include <string>


int main (void) {
    try {

	std::ifstream inputxml;
	inputxml.open("example2.xml");

	std::string inputLine; 
	std::string fullFileAsString;
	if (inputxml.is_open())
	{
		while (inputxml)
		{
			std::getline (inputxml, inputLine);
			fullFileAsString.append(inputLine);
		}
	}
	inputxml.close();

//	std::cout << fullFileAsString;
	std::size_t begin = 0;
	do 
	{
		std::size_t i = fullFileAsString.find("class=\"tat\"", begin);
		if (i == std::string::npos)
			break;
		std::size_t n = fullFileAsString.find("</p>", i);
		if (n == std::string::npos)
			break;
		std::size_t size = n - i - 12;
		std::cout << fullFileAsString.substr(i+12, size) << std::endl; 
		begin = n;
	} while (begin != std::string::npos);


    } catch (const std::exception &e) {
	std::cerr << e.what() << "\n";
	return 1;
    }

    return 0;
}
