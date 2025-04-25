CC = g++
CFLAGS = -O3 -s
TARGET = arm64
SRC = main.cpp lib.cpp
all: banner $(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@echo ""
	@echo ">> Build finished successfully!"

# Banner tampilan keren
banner:
	@echo
	@echo
	@echo "     ☆===================================☆"
	@echo
	@echo "       ~ Description Compile C++ Yeye..."
	@echo
	@echo "       - Author             :  @UnixeID"
	@echo "       - Version            :  1.0"
	@echo "       - Release            :  23 - April - 2025"
	@echo "       - Project Name       :  Compiler C++"
	@echo
	@echo "    |_______________________________________|"
	@echo "     \\______________________________________/"
	@echo
	@echo

# Format source code
format:
	clang-format -i $(SRC)
	@echo ">> Source code formatted."

# Clean build files
clean:
	rm -f $(TARGET)
	@echo ">> Cleaned build files."