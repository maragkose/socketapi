lib_LTLIBRARIES = libcppsocketapi.la

libcppsocketapiincludedir      = $(prefix)/include/cppsocketapi
libcppsocketapiinclude_HEADERS = breakdetector.h tdsocket.h timedthread.h multitimerthread.h multitimerthread.icc ../socketapi/condition.h ../socketapi/internetaddress.h ../socketapi/internetflow.h ../socketapi/portableaddress.h ../socketapi/randomizer.h ../socketapi/socketaddress.h ../socketapi/synchronizable.h ../socketapi/tdmessage.h ../socketapi/tdstrings.h ../socketapi/tdsystem.h ../socketapi/thread.h ../socketapi/tools.h ../socketapi/unixaddress.h ../socketapi/tdin6.h ../socketapi/condition.icc ../socketapi/internetaddress.icc ../socketapi/internetflow.icc ../socketapi/portableaddress.icc ../socketapi/randomizer.icc ../socketapi/socketaddress.icc ../socketapi/synchronizable.icc ../socketapi/tdmessage.icc tdsocket.icc ../socketapi/tdstrings.icc ../socketapi/thread.icc timedthread.icc ../socketapi/tools.icc ../socketapi/unixaddress.icc

libcppsocketapi_la_CXXFLAGS = -I../socketapi

libcppsocketapi_la_LIBADD = ../socketapi/libsctpsocket.la

libcppsocketapi_la_SOURCES = tdsocket.cc \
                              breakdetector.cc \
                              timedthread.cc

libcppsocketapi_la_LDFLAGS = \
   -version-info $(SOCKETAPI_CURRENT):$(SOCKETAPI_REVISION):$(SOCKETAPI_AGE)

noinst_PROGRAMS =
#t1

#t1_SOURCES =  t1.cc
#t1_LDADD = -lcppsocketapi
