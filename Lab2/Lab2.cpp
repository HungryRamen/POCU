#include <iomanip>
#include <string>
#include "Lab2.h"

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		constexpr int octLength = 12;
		constexpr int decLength = 10;
		constexpr int hecLength = 8;
		out << std::setw(octLength) << "oct" << " " << std::setw(decLength) << "dec" << " " << std::setw(hecLength) << "hex" << std::endl;
		out << std::setfill('-') << std::setw(octLength) << "" << " " << std::setw(decLength) << "" << " " << std::setw(hecLength) << "" << std::endl << std::setfill(' ');
		int num;
		std::string trash;
		while (!in.eof())
		{
			in >> num;
			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
			{
				out << std::setw(octLength) << std::oct << num << " "
					<< std::setw(decLength) << std::dec << num << " "
					<< std::setw(hecLength) << std::uppercase << std::hex << num << std::endl;
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		constexpr int posLength = 5;
		constexpr int numLength = 15;
		out << std::showpos << std::showpoint << std::internal << std::fixed << std::setprecision(3);
		float max = -FLT_MAX;
		float num;
		std::string trash;
		while (!in.eof())
		{
			in >> num;
			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
			{
				out << std::setw(posLength) << "" << std::setw(numLength) << num << std::endl;
				if (num > max)
					max = num;
			}
		}
		out << std::setw(posLength) << std::left << "max:" << std::setw(numLength) << max << std::endl;
	}
}