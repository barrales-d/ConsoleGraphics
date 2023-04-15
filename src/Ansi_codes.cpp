#include "../include/Ansi_codes.h"


void ansi_codes::reset()
{
	std::cout << "\x1b[0m";
}

void ansi_codes::hide_cursor()
{
	std::cout << "\x1b[?25l";
}

void ansi_codes::move_cursor(int up, int left)
{
	std::cout << "\x1b[" + std::to_string(left) + "D\x1b[" + std::to_string(up) + "A";
}

void ansi_codes::background(CG::Color col)
{
	std::cout << "\x1b[48;2;" +
		std::to_string(col.r) + ";" +
		std::to_string(col.g) + ";" +
		std::to_string(col.b) + "m";
}