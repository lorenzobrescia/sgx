ARCH_LIBDIR ?= /lib/$(shell $(CC) -dumpmachine)

all: py.manifest.sgx py.sig

py.manifest: py.manifest.template
	gramine-manifest \
	-Dlog_level=warning \
	-Darch_libdir=$(ARCH_LIBDIR) \
	-Dentrypoint=$(realpath $(shell sh -c "command -v python3")) \
	$< >$@

py.manifest.sgx py.sig: sgx_sign
	@:

.INTERMEDIATE: sgx_sign
sgx_sign: py.manifest
	gramine-sgx-sign \
		--manifest $< \
		--output $<.sgx

clean:
	rm -f py.manifest py.manifest.sgx py.sig py.token
