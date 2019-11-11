/*
 * Copyright 2017 Sony Corporation
 */

#ifndef EASYHTTPCPP_TEST_INTEGRATIONTEST_HTTPTESTUTIL_H_INCLUDED
#define EASYHTTPCPP_TEST_INTEGRATIONTEST_HTTPTESTUTIL_H_INCLUDED

#include <string>

#include "Poco/Buffer.h"

#include "easyhttpcpp/Request.h"
#include "easyhttpcpp/ResponseBodyStream.h"
#include "HttpsTestServer.h"

#include "HttpCacheMetadata.h"

namespace easyhttpcpp {
namespace test {

class HttpTestUtil {
public:
    static std::string getDefaultCacheParentPath();
    static std::string getDefaultCachePath();
    static std::string getDefaultCacheRootDir();
    static std::string getDefaultCacheTempDir();
    static std::string getDefaultCacheDatabaseFile();
    static std::string getDefaultCertRootDir();
    static std::string getDefaultCertRootParentDir();
    static Poco::Path createDatabasePath(const std::string parentPath);
    static std::string createCachedResponsedBodyFilePath(const std::string& cachePath, Request::HttpMethod httpMethod,
            const std::string& url);
    static std::string makeUrl(const std::string& scheme, const std::string& host, unsigned short port,
            const std::string& path);
    static std::string makeUrl(const std::string& scheme, const std::string& host, unsigned short port,
            const std::string& path, const std::string& query);
    static size_t readAllData(ResponseBodyStream::Ptr pResponseBodyStream, Poco::Buffer<char>& buffer);
    static void loadDefaultCertData();
    static void setupHttpsServerDefaultSetting(easyhttpcpp::testutil::HttpsTestServer& testServer);
    static std::string getDefaultRootCaDirectory();
    static void makeCacheDatabaseCorrupted();
    static void createInvalidCacheDatabase();
    static HttpCacheMetadata::Ptr createHttpCacheMetadata(const std::string& key, const std::string& url,
            size_t responseBodySize);
    static std::string createResponseTempFile(const std::string& tmpFilename, const std::string& responseBody,
            int no = 0);
    static std::string createResponseTempFileBySize(const std::string& tmpFilename, size_t responseBodySize);

private:
    HttpTestUtil();
    virtual ~HttpTestUtil();

};

} /* namespace test */
} /* namespace easyhttpcpp */

#endif /* EASYHTTPCPP_TEST_INTEGRATIONTEST_HTTPTESTUTIL_H_INCLUDED */
