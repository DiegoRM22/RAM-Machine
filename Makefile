CC = g++
CFLAGS = -std=c++11
SRC_DIR = .
BUILD_DIR = build
TARGET = ram

SRCS = $(wildcard $(SRC_DIR)/*.cc) $(wildcard $(SRC_DIR)/ram-machine/*.cc) $(wildcard $(SRC_DIR)/arithmetic-unit/*.cc) $(wildcard $(SRC_DIR)/data-memory/*.cc) $(wildcard $(SRC_DIR)/input-unit/*.cc) $(wildcard $(SRC_DIR)/output-unit/*.cc) $(wildcard $(SRC_DIR)/program-memory/*.cc) $(wildcard $(SRC_DIR)/instruction/add-instruction/*.cc) $(wildcard $(SRC_DIR)/instruction/div-instruction/*.cc) $(wildcard $(SRC_DIR)/instruction/load-instruction/*.cc) $(wildcard $(SRC_DIR)/instruction/mul-instruction/*.cc) $(wildcard $(SRC_DIR)/instruction/read-instruction/*.cc) $(wildcard $(SRC_DIR)/instruction/store-instruction/*.cc) $(wildcard $(SRC_DIR)/instruction/sub-instruction/*.cc) $(wildcard $(SRC_DIR)/instruction/write-instruction/*.cc)

OBJS = $(SRCS:%.cc=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)

$(BUILD_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
