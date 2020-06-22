#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

int width, height;
double x0, x1;
std::vector<std::vector<char>> graph;

std::vector<double> field(){
    std::vector<double> field;
    double step_x = (x1 - x0) / (width);
    for (int i = 0; i < width; ++i){
        field.push_back(x0 + step_x*i);
    }
    return field;
}

std::vector<double> math_function(const std::vector<double> &field){
    std::vector<double> math_graph;
    math_graph.reserve(field.size());
    for (double n: field) {
        // Math func to draw
        math_graph.push_back(-(n * n) - 0.5);
    }
    return math_graph;
}

double steps(const std::vector<double> &math_graph){
    double max;
    auto min_max = std::minmax_element(math_graph.begin(),math_graph.end());
    if (std::abs(*min_max.first) > *min_max.second){
        max = std::abs(*min_max.first);
    } else {
        max = *min_max.second;
    }
    double steps = double(height)/double(max);
    return steps;
}

void draw_func(std::vector<double> &math_graph, double steps, int above_zero_line){
    std::ofstream text_output;
    text_output.open("graph_3.txt");
    double correct_steps = steps * double(above_zero_line) / height;
    if (correct_steps < steps * 0.5){
        correct_steps = steps;
    }
    //Above 0
    for (int i = above_zero_line; i >= 0; i--){
        if (i == 0){
            for (int j = 0; j < width; j++){
                graph[i][j] = '-';
            }
        }
        for (int j = 0; j < width; j++){
            if (int(math_graph[j] * (correct_steps) >= i)) {
                for (int h = height; h > 0; h--) {
                    graph[h][j] = '#';
                }
            } else if (i != 0){
                graph[i][j] = ' ';
            }
            text_output << std::setw(1) << graph[i][j];
        }
        text_output << std::endl;
    }
    // Under 0
    for (int i = 0; i < height - above_zero_line; i++){
        for (int j = 0; j < width; j++){
            if ((int(math_graph[j] * steps) < 0) && (abs(int(math_graph[j] * (steps * (1.01 - double(above_zero_line) / height)))) >= i)){
                for (int h = 0; h < height; h++){
                    graph[h][j] = '#';
                }
            } else {
                graph[i][j] = ' ';
            }
            text_output << std::setw(1) << graph[i][j];
        }
        text_output << std::endl;
    }
    text_output.close();
}

int main() {
    std::cin >> width >> height >> x0 >> x1;
    graph.reserve(height + 1);
    for (int i = 0; i < (height + 1); i++){
        graph[i].reserve(width);
    }
    std::vector<double> field_function = field();
    std::vector<double> math_function_f = math_function(field_function);
    double local_steps = steps(math_function_f);
    draw_func(math_function_f, local_steps, 1);
    graph.clear();

    return 0;
}