#include <iostream>
#include <cmath>
#include <ctime>
#include "Greeting.h"
#include <vector>
#include <string>
#include <algorithm>

/*
 * Grade Calculator — Final Project
 * Author: Zobia Asif
 * Course: COSC 1436, 2026
 *
 * Concepts Demonstrated (Chapters 1-12)
 * -------------------------------------
 * Ch 1  - Program structure: #include directives, main() entry point
 * Ch 2  - Output with std::cout and string literals
 * Ch 3  - Variables (int, float, bool) and input with std::cin
 * Ch 4  - Arithmetic expressions to calculate the final percentage
 * Ch 5  - if / else if / else for letter-grade determination (with char)
 * Ch 6  - Sentinel-controlled looped input (negative score ends entry)
 * Ch 7  - for loop for grade cutoffs + do-while loop for assignment input
 * Ch 8  - <cmath> library: std::round() for the percentage
 * Ch 9  - User-defined function: displayGreeting() using <ctime>
 * Ch 10 - Header + implementation files: Greeting.h and Greeting.cpp
 * Ch 11 - std::vector with push_back, range-based for, and indexed iteration
 * Ch 12 - <algorithm> std::sort with a lambda; <string> getline for names
 */


int main() {
    // Variable declarations
    int total_course_points = 0;
    float A_points = 0.00;
    float B_points = 0.00;
    float C_points = 0.00;
    float D_points = 0.00;
    
    float total_points_earned = 0.00;
    float total_percentage_earned = 0.00;
    
    float assignment_score = 0.00;
    char earned_grade;
    bool score_input = true;
    int assignment = 1;

    std::vector<std::string> assignment_names;
    std::vector<float> assignment_scores;

    // Display a time-based greeting
    displayGreeting();

    // Welcome message
    std::cout << "Welcome to Your Grade Calculator!" << std::endl;
    std::cout << std::endl;

    // Get grading scheme input
    std::cout << "Grading Scheme Setup" << std::endl;
    std::cout << "====================" << std::endl;

    std::cout << "Please input the Total Points Possible: ";
    std::cin >> total_course_points;

    // Use a for loop for grade inputs
    for (char grade = 'A'; grade <= 'D'; grade++) {
        std::cout << "Please input the Minimum Points for a '" << grade << "': ";
        if (grade == 'A') {
            std::cin >> A_points;
        } else if (grade == 'B') {
            std::cin >> B_points;
        } else if (grade == 'C') {
            std::cin >> C_points;
        } else if (grade == 'D') {
            std::cin >> D_points;
        }
    }

    // Display the grading scheme
    std::cout << std::endl;
    std::cout << "The Grading Scheme You Input" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Total Points Possible in the Course: " << total_course_points << std::endl;
    std::cout << "Points needed for an 'A': " << A_points << std::endl;
    std::cout << "Points needed for a 'B': " << B_points << std::endl;
    std::cout << "Points needed for a 'C': " << C_points << std::endl;
    std::cout << "Points needed for a 'D': " << D_points << std::endl;

    // Multiple Assignment Input using do-while
    std::cout << "\nGrade Calculation\n";
    std::cout << "You will be prompted to input scores for all assignments.\n";
    std::cout << "(Input a negative number to cease input and calculate letter grade.)\n\n";

    do {
    std::cout << "Please input the points earned for Assignment " << assignment << ": ";
    std::cin >> assignment_score;

    if (assignment_score >= 0) {
        // Clear input buffer before using getline()
        std::cin.ignore();
        std::string assignment_name;
        std::cout << "Please input the name for Assignment " << assignment << ": ";
        std::getline(std::cin, assignment_name);

        assignment_names.push_back(assignment_name);
        assignment_scores.push_back(assignment_score);
        total_points_earned += assignment_score;
        assignment++;
    } else {
        score_input = false;
    }
} while (score_input);

// Create a vector of indices for sorting
std::vector<int> indices(assignment_scores.size());
for (int i = 0; i < indices.size(); i++) {
    indices[i] = i;
}

// Sort indices based on scores in descending order
std::sort(indices.begin(), indices.end(), [&](int a, int b) {
    return assignment_scores[a] > assignment_scores[b];
});

// Create new sorted vectors
std::vector<std::string> sorted_names;
std::vector<float> sorted_scores;
for (int i : indices) {
    sorted_names.push_back(assignment_names[i]);
    sorted_scores.push_back(assignment_scores[i]);
}

// Replace original vectors with sorted versions
assignment_names = sorted_names;
assignment_scores = sorted_scores;

    // Calculate percentage and round it
    total_percentage_earned = (total_points_earned / total_course_points) * 100;
    total_percentage_earned = std::round(total_percentage_earned);

// Display sorted assignments
if (!assignment_names.empty()) {
    std::cout << "\nAssignments Sorted by Score (Highest to Lowest)\n";
    std::cout << "===============================================\n";
    for (size_t i = 0; i < assignment_names.size(); i++) {
        std::cout << assignment_names[i] << ": " << assignment_scores[i] << " points\n";
    }
    std::cout << std::endl;
}

// Determine the final grade
if (total_points_earned >= A_points) {
    earned_grade = 'A';
} else if (total_points_earned >= B_points) {
    earned_grade = 'B';
} else if (total_points_earned >= C_points) {
    earned_grade = 'C';
} else if (total_points_earned >= D_points) {
    earned_grade = 'D';
} else {
    earned_grade = 'F';
}

    // Display results
    std::cout << "\nFinal Results\n";
    std::cout << "Total Points Earned: " << total_points_earned << '\n';
    std::cout << "Total Points Possible: " << total_course_points << '\n';
    std::cout << "Total Percentage: " << total_percentage_earned << '%' << '\n';
    std::cout << "Final Letter Grade: " << earned_grade << '\n';

    return 0;
}