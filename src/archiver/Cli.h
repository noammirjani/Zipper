#pragma once
#include <cxxopts.hpp>
#include <iostream>
#include <spdlog/spdlog.h>
#include <iostream>
#include <string>
#include <vector>
#include "CommandInfo.h"

class Cli
{
public:
    Cli(int, char**); 

    std::optional<CommandInfo> read();

private:
    int m_argc; 
    char ** m_argv; 
    cxxopts::Options m_cliOptions;

    cxxopts::Options create();
    void log(const cxxopts::ParseResult&) const;
};
