//1. Fraud Detection in Banking Transactions
//A banking institution monitors transactions for potential fraud by analyzing patterns in transaction size, frequency, 
//and geographical location. The transactions are sorted by suspiciousness score, calculated using a combination of these factors.
//High-risk transactions are flagged for immediate review by analysts, requiring a robust and scalable sorting mechanism to handle
//millions of records daily.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // for any calculation

// Structure to represent a transaction
struct Transaction {
    int transactionID;        // Unique transaction ID
    double amount;            // Transaction amount
    int frequency;            // Frequency of similar transactions
    std::string location;     // Geographical location of the transaction
    double suspiciousnessScore; // Calculated suspiciousness score

    // Constructor to initialize a transaction
    Transaction(int id, double amt, int freq, std::string loc)
        : transactionID(id), amount(amt), frequency(freq), location(loc) {
        suspiciousnessScore = calculateSuspiciousness();
    }

    // Function to calculate the suspiciousness score
    double calculateSuspiciousness() const {
        // Simple formula for suspiciousness (you can customize this)
        double score = (amount * 0.5) + (frequency * 0.3) + (locationRiskFactor(location) * 0.2);
        return score;
    }

    // Example: assign a risk score based on location
    double locationRiskFactor(const std::string& loc) const {
        // Simple example (real-world application would use geolocation databases)
        if (loc == "HighRiskCountry") {
            return 10.0;
        }
        return 1.0;
    }
};

// Comparator function to sort transactions based on suspiciousness score
bool compareSuspiciousness(const Transaction& t1, const Transaction& t2) {
    return t1.suspiciousnessScore > t2.suspiciousnessScore; // Higher score = higher risk
}

int main() {
    // Example transactions
    std::vector<Transaction> transactions = {
        Transaction(1, 10000.0, 5, "LowRiskCountry"),
        Transaction(2, 5000.0, 10, "HighRiskCountry"),
        Transaction(3, 300.0, 1, "LowRiskCountry"),
        Transaction(4, 15000.0, 2, "HighRiskCountry"),
        Transaction(5, 200.0, 3, "MediumRiskCountry")
    };

    // Sort transactions by suspiciousness score in descending order
    std::sort(transactions.begin(), transactions.end(), compareSuspiciousness);

    // Display sorted transactions (highest suspiciousness first)
    std::cout << "Sorted Transactions based on Suspiciousness Score:\n";
    for (const auto& txn : transactions) {
        std::cout << "Transaction ID: " << txn.transactionID
                  << ", Amount: $" << txn.amount
                  << ", Frequency: " << txn.frequency
                  << ", Location: " << txn.location
                  << ", Suspiciousness Score: " << txn.suspiciousnessScore << std::endl;
    }

    return 0;
}
