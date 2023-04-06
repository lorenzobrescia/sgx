CFLAGS += -Wall -std=c11 $(shell pkg-config --cflags secret_prov_gramine)
LDFLAGS += -Wl,--enable-new-dtags $(shell pkg-config --libs secret_prov_gramine)

server_epid: server.c
	$(CC) $< $(CFLAGS) $(LDFLAGS) -lsecret_prov_verify_epid -pthread -o $@
	
clean:
	rm -f server_epid
