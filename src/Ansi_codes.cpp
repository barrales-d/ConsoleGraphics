#include "../include/Ansi_codes.h"

using namespace Ansi;

const std::string Codes::move_cursor(int up, int left)
{
	return "\033[" + std::to_string(left) + "D\033[" + std::to_string(up) + "A";
}

const std::string Codes::background(CG::Color col)
{
	return "\033[48;2;" +
		std::to_string(col.r) + ";" +
		std::to_string(col.g) + ";" +
		std::to_string(col.b) + "m";
}
