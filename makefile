OUT_DIR := build
compile:
	clang++ main.cpp -std=c++20 -Wall -Wextra -o $(OUT_DIR)/main.exe
