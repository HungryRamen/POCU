#include <iomanip>
#include "Lab2.h"
constexpr int OCT_LENGTH = 12;
constexpr int DEC_LENGTH = 10;
constexpr int HEX_LENGTH = 8;
constexpr int POS_LENGTH = 5;
constexpr int NUM_LENGTH = 15;
namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << std::setw(OCT_LENGTH) << "oct" << " " << std::setw(DEC_LENGTH) << "dec" << " " << std::setw(HEX_LENGTH) << "hex" << std::endl;
		out << std::setfill('-') << std::setw(OCT_LENGTH) << "" << " " << std::setw(DEC_LENGTH) << "" << " " << std::setw(HEX_LENGTH) << "" << std::endl << std::setfill(' ');

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
			out << std::setw(OCT_LENGTH) << std::oct << num << " "
				<< std::setw(DEC_LENGTH) << std::dec << num << " "
				<< std::setw(HEX_LENGTH) << std::uppercase << std::hex << num << std::endl;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float max = FLT_MIN;
		out << std::showpos << std::showpoint << std::internal << std::fixed << std::setprecision(3);
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
			out << std::setw(POS_LENGTH) << "" << std::setw(NUM_LENGTH) << num << std::endl;
			if (num > max)
				max = num;
		}
		out << std::setw(POS_LENGTH) << "max:" << std::setw(NUM_LENGTH) << max << std::endl;
	}
}