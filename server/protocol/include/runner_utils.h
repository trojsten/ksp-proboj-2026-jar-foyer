#pragma once

#include<sstream>
#include<string>
#include<vector>


namespace runner{
    enum class Status{
        Ok,
        Error,
        Died
    };

    const std::string dot = ".";

    /// @brief Send command without payload to runner
    /// @param command command, that should be executed
    void sendCommand(const std::string);

    /// @brief Send command with payload to runner
    /// @param command command, that should be executed
    /// @param payload payload of that command
    void sendCommand(const std::string, const std::string&);

    /// @brief Send command with payload and arguments to runner
    /// @param command command, that should be executedi
    /// @param arguments arguments of that command
    /// @param payload payload of that command
    void sendCommand(const std::string, const std::vector<std::string>&, const std::string&);

    /// @brief Read data from runner
    /// @param status returned status (Ok, Error, Died)
    /// @return `data_stream` containing the data
    std::stringstream read(Status&);

    /// @brief Read status and ignore payload
    /// @return returned status (Ok, Error, Died)
    Status read_status();
};
