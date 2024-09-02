#include <iostream>
#include <spdlog/spdlog.h>

int main()
{
	std::cout << fmt::format("Hello!!!") << std::endl;

	for (int i = 0; i < 10; i++)
	{
		spdlog::info("Hello, spdlog! {}", i);
	}

	return 0;
}
