if [[ -z ${SYSTEMC_VERSION} ]]; then
    echo "Please set SYSTEMC_VERSION environment variable..."
    echo "IE:"
    echo "    export SYSTEMC_VERSION=2.3.3"
    
else
    echo "SYSTEMC_VERSION set to ${SYSTEMC_VERSION}"
    if [[ -z ${SYSTEMC_HOME} ]]; then
        echo "Please set SYSTEMC_HOME environment variable..."
    else
        echo "SYSTEMC_VERSION set to ${SYSTEMC_HOME}"
        export LD_LIBRARY_PATH=${SYSTEMC_HOME}/lib:$LD_LIBRARY_PATH
        export LD_LIBRARY_PATH=/home/engest/devel/systemc/work/projects/vdm_proto/lib/Debug:$LD_LIBRARY_PATH
        export LD_LIBRARY_PATH=/home/engest/devel/systemc/work/projects/vdm_proto/test/tlmdriver/lib/Debug:$LD_LIBRARY_PATH
    fi
fi
