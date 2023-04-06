all: somma somma.manifest.sgx somma.sig

somma: somma.c
	gcc somma.c -o somma

somma.manifest: somma.manifest.template
	gramine-manifest \
	-Dlog_level=warning \
	$< >$@

somma.manifest.sgx somma.sig: sgx_sign
	@:

.INTERMEDIATE: sgx_sign
sgx_sign: somma.manifest
	gramine-sgx-sign \
		--manifest $< \
		--output $<.sgx

clean:
	rm -f somma somma.manifest somma.manifest.sgx somma.sig somma.token
