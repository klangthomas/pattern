set(PATTERN_MODULE_VERSION_NUMBER "0.0.1")

juce_add_modules(INSTALL_PATH "include/Pattern-${PATTERN_MODULE_VERSION_NUMBER}/modules"
    ALIAS_NAMESPACE pattern
	pattern_base
	pattern_creational
	pattern_structural
	pattern_behavioral
    )
