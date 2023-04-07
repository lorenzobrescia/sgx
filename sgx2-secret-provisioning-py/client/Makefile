CFLAGS += -Wall -std=c11 $(shell pkg-config --cflags secret_prov_gramine)
LDFLAGS += -Wl,--enable-new-dtags $(shell pkg-config --libs secret_prov_gramine)

server_dcap: server.c
	$(CC) $< $(CFLAGS) $(LDFLAGS) -Wl,--no-as-needed -lsgx_urts -lsecret_prov_verify_dcap -pthread -o $@
	
clean:
	rm -f server_dcap
