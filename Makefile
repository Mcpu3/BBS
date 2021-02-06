MAKE = make

.PHONY: all
all: client server

.PHONY: client
client:
	$(MAKE) -C Client -j

.PHONY: server
server:
	$(MAKE) -C Server -j

.PHONY: clean
clean:
	$(MAKE) -C Client -j $@
	$(MAKE) -C Server -j $@