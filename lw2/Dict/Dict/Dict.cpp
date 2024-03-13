
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>

std::map<std::string, std::string> loadDictionary(const std::string& filename) 
{
    std::ifstream file(filename);
    std::map<std::string, std::string> dictionary;

    if (file.is_open()) 
    {
        std::string line;
        while (std::getline(file, line)) 
        {
            size_t pos = line.find(':');
            if (pos != std::string::npos) 
            {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                dictionary[key] = value;
            }
        }
    }

    return dictionary;
}

void saveDictionary(const std::string& filename, const std::map<std::string, std::string>& dictionary)
{
    std::ofstream file(filename);

    if (file.is_open()) 
    {
        for (const auto pair : dictionary) 
        {
            file << pair.first << ":" << pair.second << "\n";
        }
    }
}

void translateWord(const std::string& word, std::map<std::string, std::string>& dictionary, bool& changed)
{

    auto it = dictionary.find(word);
    if (it != dictionary.end()) 
    {
        std::cout << it->second << std::endl;
    }
    else 
    {
        std::string translation;
        std::cout << "Неизвестное слово \"" << word << "\" . Введите перевод или пустую строку для отказа.\n";
        std::getline(std::cin, translation);

        if (!translation.empty()) 
        {
            dictionary[word] = translation;
            std::cout << "Слово \"" << word << "\" сохранено в словаре как “" << translation << "”.\n";
            changed = true;
        }
        else
        {
            std::cout << "Слово \"" << word << "\" проигнорировано\n";
        }
    }
}

int main(int argc, char* argv[]) 
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc != 2) 
    {
        std::cout << "Использовать: " << argv[0] << " <файл словаря>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::map<std::string, std::string> dictionary;

    std::fstream dictFile(filename);
    if (dictFile.is_open()) 
    {
        dictionary = loadDictionary(filename);
    }

    bool changesMade = false;

    while (true) 
    {
        std::cout << "Введите слово для перевода или ... для выхода: \n";
        std::string word;
        std::getline(std::cin, word);

        if (word == "...") 
        {
            if (changesMade) 
            {
                std::string saveChanges;
                std::cout << "Хотите сохранить изменения в словаре? Введите Y или y для сохранения перед выходом.: \n";
                std::getline(std::cin, saveChanges);

                if (saveChanges == "y" or "Y") 
				{
					saveDictionary(filename, dictionary);
				}
			}
			break;
		}
		translateWord(word, dictionary, changesMade);
	}
	return 0;
}