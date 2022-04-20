ifeq "a$(SYSTEMC_VERSION)" "a"
    $(error "Please set SYSTEMC_VERSION environment variable...\nIE:\nexport SYSTEMC_VERSION=2.3.3")
endif
ifeq "a$(SYSTEMC_HOME)" "a"
    $(error "Please set SYSTEMC_HOME environment variable...")
endif