#include <pp/Common.h>

#include <string>
#include <vector>

PP_NAMESPACE_BEGIN

std::vector<std::string> Split(std::string text, const std::string& delim)
{
    std::vector<std::string> result;
    while (true) {
        size_t begin = text.find_last_of(delim);
        if (begin == std::string::npos) {
            result.emplace_back(text);
            return result;
        } else {
            result.emplace_back(text.substr(begin + 1));
            text.resize(begin);
        }
    }

    return result;
}

std::string Join(const std::vector<std::string>& words, const std::string& delim)
{
	std::string result;
	for (size_t i = 0; i < words.size(); ++i)
	{
		result += words[i];
		if (i < words.size() - 1)
			result += delim;
	}
	return result;
}

std::string ToLower(std::string str)
{
    transform(begin(str), end(str), begin(str), [](unsigned char c) { return (char)tolower(c); });
    return str;
}

std::string ToUpper(std::string str)
{
    transform(begin(str), end(str), begin(str), [](unsigned char c) { return (char)toupper(c); });
    return str;
}

std::string ToString(EMods mods)
{
	std::string result = "";

	std::vector<std::string> modStrings;

	// Keymods
	if (mods & Key1)
		modStrings.emplace_back("K1");
	if (mods & Key2)
		modStrings.emplace_back("K2");
	if (mods & Key3)
		modStrings.emplace_back("K3");
	if (mods & Key4)
		modStrings.emplace_back("K4");
	if (mods & Key5)
		modStrings.emplace_back("K5");
	if (mods & Key6)
		modStrings.emplace_back("K6");
	if (mods & Key7)
		modStrings.emplace_back("K7");
	if (mods & Key8)
		modStrings.emplace_back("K8");
	if (mods & Key9)
		modStrings.emplace_back("K9");
	if (mods & Key10)
		modStrings.emplace_back("K10");

	// Cheap out
	if (mods & NoFail)
		modStrings.emplace_back("NF");
	if (mods & SpunOut)
		modStrings.emplace_back("SO");

	// Visiblity
	if (mods & Hidden)
		modStrings.emplace_back("HD");
	if (mods & Flashlight)
		modStrings.emplace_back("FL");

	// Speed
	if (mods & DoubleTime)
		modStrings.emplace_back("DT");
	if (mods & HalfTime)
		modStrings.emplace_back("HT");

	// Difficulty
	if (mods & HardRock)
		modStrings.emplace_back("HR");
	if (mods & Easy)
		modStrings.emplace_back("EZ");

	if (modStrings.empty())
		return "None";

	return Join(modStrings, ",");
}

std::string GamemodeSuffix(EGamemode gamemode)
{
	switch (gamemode)
	{
	case EGamemode::Osu:   return "";
	case EGamemode::Taiko: return "_taiko";
	case EGamemode::Catch: return "_fruits";
	case EGamemode::Mania: return "_mania";
	default: return "";
	}
}

std::string GamemodeName(EGamemode gamemode)
{
	switch (gamemode)
	{
	case EGamemode::Osu:   return "osu!";
	case EGamemode::Taiko: return "osu!taiko";
	case EGamemode::Catch: return "osu!catch";
	case EGamemode::Mania: return "osu!mania";
	default: return "osu!";
	}
}

std::string GamemodeTag(EGamemode gamemode)
{
	switch (gamemode)
	{
	case EGamemode::Osu:   return "osu";
	case EGamemode::Taiko: return "taiko";
	case EGamemode::Catch: return "catch_the_beat";
	case EGamemode::Mania: return "osu_mania";
	default: return "osu";
	}
}

EGamemode ToGamemode(std::string modeString)
{
	modeString = ToLower(modeString);
	if (modeString == "osu" || modeString == "osu!" || modeString == "standard")
		return EGamemode::Osu;
	else if (modeString == "taiko" || modeString == "osu!taiko")
		return EGamemode::Taiko;
	else if (modeString == "catch" || modeString == "osu!catch" || modeString == "fruits" || modeString == "catchthebeat" || modeString == "catch the beat")
		return EGamemode::Catch;
	else if (modeString == "mania" || modeString == "osu!mania")
		return EGamemode::Mania;
	else
        return EGamemode::Osu;
}

PP_NAMESPACE_END
