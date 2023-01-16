#pragma once

#include <juce_core/juce_core.h>
#include <spdlog/spdlog.h>

///
/// \brief Logger bridge from juce to spdlog.
///
/// This only outputs to spdlog::info.
///
class LoggerSpdJuce : public juce::Logger
{
public:
	LoggerSpdJuce ( ) {}

	void logMessage ( const juce::String& message ) override { spdlog::info ( message.toStdString ( ) ); }
};