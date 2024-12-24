//2. Stock Market Data Analysis
//A financial technology company needs to process real-time stock market data consisting of millions of trades every minute.
//Each trade record includes the timestamp, stock symbol, trade price, and trade volume. To identify patterns and generate 
//analytics, the trades must be sorted by timestamp. For deeper insights, the company also requires sorting by stock symbol
//and grouping by trading volume trends. Handling this large-scale data efficiently is crucial for providing timely analytics to clients.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <ctime>

// Structure to represent a single trade record
struct Trade {
    std::time_t timestamp;   // Time of the trade (Unix timestamp)
    std::string stockSymbol; // Stock symbol (e.g., "AAPL", "GOOG")
    double price;            // Trade price
    int volume;              // Trade volume (number of shares)

    // Constructor to initialize the trade
    Trade(std::time_t ts, const std::string& symbol, double p, int v)
        : timestamp(ts), stockSymbol(symbol), price(p), volume(v) {}
};

// Comparator function to sort trades by timestamp
bool compareByTimestamp(const Trade& t1, const Trade& t2) {
    return t1.timestamp < t2.timestamp;  // Ascending order of timestamp
}

// Comparator function to sort trades by stock symbol
bool compareByStockSymbol(const Trade& t1, const Trade& t2) {
    return t1.stockSymbol < t2.stockSymbol; // Alphabetical order of stock symbol
}

// Function to group trades by stock symbol and analyze trading volume trends
void analyzeVolumeTrends(const std::vector<Trade>& trades) {
    std::unordered_map<std::string, std::vector<int>> volumeBySymbol;

    // Group trades by stock symbol and accumulate volumes
    for (const auto& trade : trades) {
        volumeBySymbol[trade.stockSymbol].push_back(trade.volume);
    }

    // Display volume trends for each stock symbol
    for (const auto& entry : volumeBySymbol) {
        const std::string& symbol = entry.first;
        const std::vector<int>& volumes = entry.second;

        std::cout << "Volume trends for stock: " << symbol << "\n";
        for (int i = 0; i < volumes.size(); ++i) {
            std::cout << "Trade " << i + 1 << ": Volume = " << volumes[i] << "\n";
        }
        std::cout << "\n";
    }
}

int main() {
    // Example trades
    std::vector<Trade> trades = {
        Trade(1609459200, "AAPL", 150.0, 1000),
        Trade(1609459260, "GOOG", 1750.0, 500),
        Trade(1609459320, "AAPL", 152.0, 2000),
        Trade(1609459380, "GOOG", 1760.0, 1500),
        Trade(1609459440, "AAPL", 153.0, 1500),
        Trade(1609459500, "MSFT", 210.0, 1200)
    };

    // Step 1: Sort trades by timestamp
    std::sort(trades.begin(), trades.end(), compareByTimestamp);

    // Display trades sorted by timestamp
    std::cout << "Trades sorted by timestamp:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp << ", Stock: " << trade.stockSymbol
                  << ", Price: " << trade.price << ", Volume: " << trade.volume << "\n";
    }
    std::cout << "\n";

    // Step 2: Sort trades by stock symbol
    std::sort(trades.begin(), trades.end(), compareByStockSymbol);

    // Display trades sorted by stock symbol
    std::cout << "Trades sorted by stock symbol:\n";
    for (const auto& trade : trades) {
        std::cout << "Stock: " << trade.stockSymbol << ", Timestamp: " << trade.timestamp
                  << ", Price: " << trade.price << ", Volume: " << trade.volume << "\n";
    }
    std::cout << "\n";

    // Step 3: Group trades by stock symbol and analyze volume trends
    analyzeVolumeTrends(trades);

    return 0;
}
