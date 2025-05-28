#ifndef CSR_HTTP_MESSAGE_SERVERREQUEST

#include "Request.hpp"
#include "UploadedFile.hpp"

namespace Csr {
namespace Http {
namespace Message {

/**
 * Representation of an incoming, server-side HTTP request.
 *
 * Per the HTTP specification, this interface includes properties for
 * each of the following:
 *
 * - Protocol version
 * - HTTP method
 * - URI
 * - Headers
 * - Message body
 *
 * Additionally, it encapsulates all data as it has arrived at the
 * application from the CGI environment, including:
 *
 * - Server environment variables.
 * - Any cookies provided.
 * - Query string arguments.
 * - Upload files, if any.
 * - Parsed body parameters.
 *
 * Additionally, this interface recognizes the utility of introspecting a
 * request to derive and match additional parameters (e.g., via URI path
 * matching, decrypting cookie values, deserializing non-form-encoded body
 * content, matching authorization headers to users, etc). These parameters
 * are stored in an "attributes" property.
 */
class ServerRequest : public Request {
    // Add private members here per implementation.

    public:
    /**
     * Create a new server request.
     *
     * Note that server parameters are taken precisely as given - no parsing/processing
     * of the given values is performed. In particular, no attempt is made to
     * determine the HTTP method or URI, which must be provided explicitly.
     *
     * @param method The HTTP method associated with the request.
     * @param uri The URI associated with the request. 
     * @param serverParams An array of Server API (SAPI) parameters with
     *     which to seed the generated request instance.
     */
    ServerRequest(const char* method, const char* uri, char** serverParams);

    /**
     * Retrieve server parameter.
     *
     * Retrieves data related to the incoming request environment.
     *
     * Typically, HTTP headers are pulled from "HTTP_" prefixed environment
     * variables whereas the server params are non-prefixed and created by
     * the web server.
     *
     * @return The value of the server parameter or a null-terminated string
     *     if it cannot be found.
     */
    const char* getServerParam(const char* name);

    /**
     * Retrieve cookies.
     *
     * Retrieves cookies sent by the client to the server.
     *
     * @return The value of the cookie or a null-terminated string if it cannot
     *     be found.
     */
    const char* getCookieParam(const char* name);

    /**
     * Retrieve query string arguments.
     *
     * Retrieves the urldecoded query string arguments, if any.
     *
     * Note: the query params might not be in sync with the URI or server
     * params. If you need to ensure you are only getting the original
     * values, you may need to parse the query string from
     * `getUri()->getQuery()` or from the `QUERY_STRING` server param.
     *
     * @return The value of the query parameter or a null-terminated string if
     *     none can be found.
     */
    const char* getQueryParam(const char* name);

    /**
     * Retrieve file upload data.
     *
     * Uploaded file names are specified by their respective HTML form input
     * element name.
     *
     * Uploaded files are ONLY parsed and made available by this method
     * when the request Content-Type is multipart/form-data, and the request
     * method is POST.
     *
     * @return An uploaded file instance or null if none can be found.
     */
    UploadedFile* getUploadedFile(const char* name);

    /**
     * Retrieve a parameter provided in the request body.
     *
     * Retrieves the urldecoded body parameters, if any.
     *
     * Request body parameters are ONLY parsed and made available by this method
     * when the request Content-Type is either application/x-www-form-urlencoded
     * or multipart/form-data, and the request method is POST.
     * 
     * @return The value of the body parameter or a null-terminated string
     *     if none can be found. If the request Content-Type is NOT either
     *     application/x-www-form-urlencoded or multipart/form-data or the
     *     request method is NOT POST then this method returns a
     *     null-terminated string.
     */
    const char* getBodyParam(const char* name);

    /**
     * Retrieve a single derived request attribute.
     *
     * The request "attributes" may be used to allow injection of any
     * parameters derived from the request: e.g., the results of path
     * match operations; the results of decrypting cookies; the results of
     * deserializing non-form-encoded message bodies; etc. Attributes
     * will be application and request specific.
     *
     * If the attribute has not been previously set, returns the default value
     * as provided.
     *
     * This method obviates the need for a hasAttribute() method, as it allows
     * specifying a default value to return if the attribute is not found.
     *
     * @param name The attribute name.
     * @param def Default value to return if the attribute does not exist.
     * @return The value of the attribute or the value of `def` if the
     *     attribute cannot be found.
     */
    const char* getAttribute(const char* name, const char* def = "");

    /**
     * Changes the specified derived request attribute.
     *
     * This method allows setting a single derived request attribute as
     * described in getAttribute().
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated attribute.
     *
     * @see getAttribute()
     * @param name The attribute name.
     * @param value The value of the attribute.
     */
    void setAttribute(const char* name, const char* value);

    /**
     * Deletes the specified derived request attribute.
     *
     * This method allows removing a single derived request attribute as
     * described in getAttribute().
     *
     * @see getAttribute()
     * @param name The attribute name to delete.
     */
    void removeAttribute(const char* name);

    ~ServerRequest();
};

}}} // Csr::Http::Message
#define CSR_HTTP_MESSAGE_SERVERREQUEST
#endif // CSR_HTTP_MESSAGE_SERVERREQUEST
