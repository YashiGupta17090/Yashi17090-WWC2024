//5. Scheduling Ads for a Social Media Platform
//social media platform runs advertisements for multiple advertisers, each targeting specific user demographics. 
//Ads are prioritized based on factors like bid amount, engagement rates, and the remaining budget. To maximize revenue and 
//user satisfaction, the platform must sort and schedule ads in real-time for millions of users while balancing competing priorities. 
//Efficient sorting directly impacts ad visibility and revenue generation.
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>

struct Ad {
    std::string adId;         // Unique ID for the ad
    std::string advertiser;   // Advertiser's name
    double bidAmount;         // Bid amount for the ad
    double engagementRate;    // Engagement rate (could be percentage)
    double remainingBudget;   // Remaining budget for the ad
    long long timeSubmitted;  // Time the ad was submitted (for handling late arrivals)

    // Constructor
    Ad(std::string id, std::string advertiserName, double bid, double engagement, double budget, long long time)
        : adId(id), advertiser(advertiserName), bidAmount(bid), engagementRate(engagement), 
          remainingBudget(budget), timeSubmitted(time) {}

    // Function to calculate the ad score based on bid, engagement, and remaining budget
    double calculateAdScore() const {
        double budgetWeight = 0.3;   // Weight for the remaining budget
        double engagementWeight = 0.4;  // Weight for engagement rate
        double bidWeight = 0.3;      // Weight for bid amount

        // You can adjust this formula based on your priorities, this is an example
        return bidAmount * bidWeight + engagementRate * engagementWeight + remainingBudget * budgetWeight;
    }

    // Comparator function for priority queue
    bool operator<(const Ad& other) const {
        double score1 = calculateAdScore();
        double score2 = other.calculateAdScore();
        
        // Prioritize higher score, in case of tie, prioritize earlier submission (smaller time)
        if (score1 == score2) {
            return timeSubmitted > other.timeSubmitted; // Earlier submitted ad gets higher priority
        }
        return score1 < score2; // Higher score means higher priority
    }
};

// Function to simulate scheduling ads
void scheduleAds(std::vector<Ad>& ads) {
    // Use a priority queue to dynamically sort ads based on ad scores
    std::priority_queue<Ad> pq;

    // Add all ads to the priority queue
    for (const auto& ad : ads) {
        pq.push(ad);
    }

    // Schedule ads based on priority
    std::cout << "Scheduling ads based on priority:\n";
    while (!pq.empty()) {
        const Ad& ad = pq.top();
        pq.pop();
        std::cout << "Ad ID: " << ad.adId << ", Advertiser: " << ad.advertiser
                  << ", Bid: " << ad.bidAmount << ", Engagement Rate: " << ad.engagementRate
                  << ", Remaining Budget: " << ad.remainingBudget << ", Score: " << ad.calculateAdScore() << "\n";
    }
}

int main() {
    // Simulating some ads arriving with different attributes
    std::vector<Ad> ads = {
        Ad("Ad1", "AdvertiserA", 500, 0.8, 3000, 100),
        Ad("Ad2", "AdvertiserB", 400, 0.6, 5000, 50),
        Ad("Ad3", "AdvertiserC", 450, 0.9, 2000, 200),
        Ad("Ad4", "AdvertiserD", 600, 0.75, 4000, 80),
        Ad("Ad5", "AdvertiserE", 300, 0.85, 1500, 10)
    };

    // Call the function to schedule ads based on their priority
    scheduleAds(ads);

    return 0;
}


