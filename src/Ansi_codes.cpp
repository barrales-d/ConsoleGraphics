#include "../include/Ansi_codes.h"

using namespace Ansi;

const std::string Codes::move_cursor(int up, int left)
{
	return "\x1b[" + std::to_string(left) + "D\x1b[" + std::to_string(up) + "A";
}

const std::string Codes::background(CG::Color col)
{
	return "\x1b[48;2;" +
		std::to_string(col.r) + ";" +
		std::to_string(col.g) + ";" +
		std::to_string(col.b) + "m";
}
