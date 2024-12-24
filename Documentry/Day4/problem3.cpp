//3. Video Streaming Platform Recommendation System
A video streaming platform generates recommendations for users based on the popularity of movies and TV shows. Each item in the
//catalog has attributes like total views, user ratings, and release year. The system must sort the catalog to prioritize trending 
//content by combining popularity and recency. Furthermore, personalized recommendations require sorting by relevance to each user's 
//viewing history, making the sorting process dynamic and computationally intensive.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

// Structure to represent a video item (movie/TV show)
struct Video {
    std::string title;        // Title of the video
    int totalViews;           // Total number of views
    double userRating;        // Average user rating
    int releaseYear;          // Release year
    std::string genre;        // Genre (e.g., "Action", "Comedy")

    // Constructor to initialize the video data
    Video(std::string t, int views, double rating, int year, std::string g)
        : title(t), totalViews(views), userRating(rating), releaseYear(year), genre(g) {}

    // Calculate a combined popularity score based on views, ratings, and recency
    double calculatePopularityScore() const {
        // Simple weighted score: 50% views, 30% ratings, 20% recency
        int currentYear = 2024; // Assume current year is 2024
        double recencyFactor = 1.0 / (currentYear - releaseYear + 1); // More recent = higher score
        return totalViews * 0.5 + userRating * 0.3 + recencyFactor * 100 * 0.2;
    }

    // Function to calculate the similarity score between this video and the user's history
    double calculateRelevanceScore(const std::unordered_map<std::string, double>& userHistory) const {
        // Assuming the userHistory stores relevance score for each genre
        auto it = userHistory.find(genre);
        if (it != userHistory.end()) {
            return it->second * 0.8 + userRating * 0.2; // Weighted relevance (based on genre and rating)
        }
        return 0.0;
    }
};

// Comparator function to sort videos based on popularity
bool compareByPopularity(const Video& v1, const Video& v2) {
    return v1.calculatePopularityScore() > v2.calculatePopularityScore(); // Higher score = higher priority
}

// Comparator function to sort videos based on relevance to a specific user
bool compareByRelevance(const Video& v1, const Video& v2, const std::unordered_map<std::string, double>& userHistory) {
    double relevance1 = v1.calculateRelevanceScore(userHistory);
    double relevance2 = v2.calculateRelevanceScore(userHistory);
    return relevance1 > relevance2; // Higher relevance = higher priority
}

int main() {
    // Catalog of videos (movies/TV shows)
    std::vector<Video> catalog = {
        Video("Movie A", 500000, 4.5, 2022, "Action"),
        Video("Movie B", 1500000, 4.0, 2020, "Comedy"),
        Video("TV Show A", 200000, 4.8, 2021, "Drama"),
        Video("Movie C", 3000000, 3.9, 2019, "Action"),
        Video("TV Show B", 800000, 4.6, 2023, "Comedy")
    };

    // Example user history (relevance scores for genres the user prefers)
    std::unordered_map<std::string, double> userHistory = {
        {"Action", 0.9},
        {"Comedy", 0.7},
        {"Drama", 0.5}
    };

    // Step 1: Sort videos by popularity (views, ratings, recency)
    std::sort(catalog.begin(), catalog.end(), compareByPopularity);
    
    // Display sorted catalog by popularity
    std::cout << "Catalog sorted by popularity:\n";
    for (const auto& video : catalog) {
        std::cout << "Title: " << video.title << ", Views: " << video.totalViews
                  << ", Rating: " << video.userRating << ", Release Year: " << video.releaseYear << "\n";
    }
    std::cout << "\n";

    // Step 2: Sort videos by relevance to a specific user
    std::sort(catalog.begin(), catalog.end(), [&userHistory](const Video& v1, const Video& v2) {
        return compareByRelevance(v1, v2, userHistory);
    });

    // Display sorted catalog by relevance to user
    std::cout << "Catalog sorted by relevance to the user:\n";
    for (const auto& video : catalog) {
        std::cout << "Title: " << video.title << ", Genre: " << video.genre
                  << ", Rating: " << video.userRating << ", Release Year: " << video.releaseYear << "\n";
    }

    return 0;
}
