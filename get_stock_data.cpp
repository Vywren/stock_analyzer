#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

// Function to read the API key from a text file
std::string ReadAPIKeyFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string apiKey;
        std::getline(file, apiKey);
        file.close();
        return apiKey;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return "";
    }
}

// Callback function to write response data into a string
size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *s) {
    s->append((char *)contents, size * nmemb);
    return size * nmemb;
}


int main() {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        // Read the API key from the text file
        std::string apiKey = ReadAPIKeyFromFile("api_key.txt");
        if (apiKey.empty()) {
            return 1;
        }

        std::string symbol = "IBM"; // Replace with the stock symbol you want to fetch data for
        // std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=" + symbol + "&apikey=" + apiKey;
        std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" + symbol + "&interval=5min&apikey=" + apiKey;
        // Free stock API service covering the majority of alphavantage datasets for up to 25 requests per day. 
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Response received:" << std::endl;
            std::cout << readBuffer << std::endl;
        }
    }

    return 0;
}

// compile with g++ -o test_api get_stock_data.cpp -lcurl
// pipe output to a file
//TODO: Make a MakeFile