#include <ConsoleGraphics/Ansi.h>

void ansi::reset()
{
	std::cout << "\x1b[0m";
}

void ansi::clear_screen()
{
	std::cout << "\x1b[2J";
}

void ansi::hide_cursor()
{
	std::cout << "\x1b[?25l";
}

void ansi::move_cursor(int up, int left)
{
	std::cout << "\x1b[" + std::to_string(left) + "D\x1b[" + std::to_string(up) + "A";
}

void ansi::background(CG::Color col)
{
	std::cout << "\x1b[48;2;" +
		std::to_string(col.r) + ";" +
		std::to_string(col.g) + ";" +
		std::to_string(col.b) + "m";
}

void ansi::foreground(CG::Color col)
{
	std::cout << "\x1b[38;2;" +
		std::to_string(col.r) + ";" +
		std::to_string(col.g) + ";" +
		std::to_string(col.b) + "m";
}

void ansi::linewrap(bool enable)
{
	if (enable)
		std::cout << "\x1b[7h";
	else
		std::cout << "\x1b[?7l";;
}
