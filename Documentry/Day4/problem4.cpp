//4. Hospital Resource Allocation
//A hospital management system needs to sort incoming patients in the emergency department based on triage priority,
//severity of condition, and arrival time. The sorted list determines the order in which patients are seen by medical professionals.
//Additionally, during peak times, the system must dynamically adjust the sorting as new patients arrive, ensuring that life-threatening 
//cases are prioritized while maintaining fairness.
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <ctime>

// Structure to represent a patient
struct Patient {
    std::string name;          // Name of the patient
    int triagePriority;        // Priority of triage: 1 (most urgent), 2, 3 (least urgent)
    int severity;              // Severity of the condition (higher is more severe)
    std::time_t arrivalTime;   // Timestamp of patient arrival
    // Constructor
    Patient(std::string n, int tp, int s, std::time_t at)
        : name(n), triagePriority(tp), severity(s), arrivalTime(at) {}

    // Comparator function for priority queue (max-heap)
    bool operator<(const Patient& other) const {
        // Prioritize first by triagePriority, then by severity (high severity first), then by arrivalTime (earliest first)
        if (triagePriority == other.triagePriority) {
            if (severity == other.severity) {
                return arrivalTime > other.arrivalTime; // Earlier arrival has higher priority
            }
            return severity < other.severity; // Higher severity has higher priority
        }
        return triagePriority > other.triagePriority; // Lower triagePriority means higher urgency
    }
};

// Function to simulate the hospital resource allocation
void allocateResources(std::vector<Patient>& patients) {
    // Using a priority queue to dynamically prioritize patients based on the comparator
    std::priority_queue<Patient> pq;

    // Add all patients to the priority queue
    for (const auto& patient : patients) {
        pq.push(patient);
    }

    // Allocate resources to patients based on priority
    std::cout << "Allocating resources to patients in order of priority:\n";
    while (!pq.empty()) {
        Patient currentPatient = pq.top();
        pq.pop();
        std::cout << "Patient: " << currentPatient.name 
                  << ", Triage Priority: " << currentPatient.triagePriority
                  << ", Severity: " << currentPatient.severity
                  << ", Arrival Time: " << currentPatient.arrivalTime << "\n";
    }
}

int main() {
    // Simulating patient arrival with different triage priority, severity, and arrival time
    std::vector<Patient> patients = {
        Patient("kalu saith", 1, 8, std::time(0) - 60), // Life-threatening, severe
        Patient("Bhola", 3, 3, std::time(0) - 120), // Non-urgent, mild
        Patient("chamchi", 2, 7, std::time(0) - 180), // Urgent, moderate
        Patient("pyari", 1, 5, std::time(0) - 30), // Life-threatening, moderate
        Patient("Billu", 2, 6, std::time(0) - 90), // Urgent, moderate
    };

    // Call function to allocate resources and prioritize patients
    allocateResources(patients);

    return 0;
}
