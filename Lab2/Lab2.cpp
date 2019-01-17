#include <iomanip>
#include "Lab2.h"
namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		const int octLength = 12;
		const int decLength = 10;
		const int hexLength = 8;
		out << std::setw(octLength) << "oct" << " " << std::setw(decLength) << "dec" << " " << std::setw(hexLength) << "hex" << std::endl;
		out << std::setfill('-') << std::setw(octLength) << "" << " " << std::setw(decLength) << "" << " " << std::setw(hexLength) << "" << std::endl << std::setfill(' ');

		while (!in.eof())
		{

			int num;
			in >> num;
			if (in.fail())
			{
				in.clear();
				in.ignore(LLONG_MAX, ' ');

				continue;
			}
			if (num < 0)
			{
				continue;
			}
			out << std::setw(octLength) << std::oct << num << " "
				<< std::setw(decLength) << std::dec << num << " "
				<< std::setw(hexLength) << std::uppercase << std::hex << num << std::endl;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		const int posLength = 5;
		const int numLength = 15;
		float max;
		in >> max;
		out << std::showpos << std::showpoint << std::internal<<std::fixed;
		out.precision(3);
		if (in.fail())
		{
			in.clear();
			in.ignore(LLONG_MAX, ' ');
		}
		else
		{
			out << std::setw(posLength) << "" << std::setw(numLength) << max << std::endl;
		}
		while (!in.eof())
		{
			float num;
			in >> num;
			if (in.fail())
			{
				in.clear();
				in.ignore(LLONG_MAX, ' ');

				continue;
			}
			out << std::setw(posLength) << "" <<std::setw(numLength)<< num << std::endl;
			if (num > max)
				max = num;
		}
		out << std::setw(posLength) << "max:" << std::setw(numLength) << max << std::endl;
	}
}