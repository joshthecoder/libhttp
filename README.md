libhttp
=======
A HTTP client/server library for C!

Goals of the project
--------------------
- Be as lightweight as possible.
- Focus on HTTP and not become a swissarmy knife of protocols.
- Provide a low-level API to the HTTP protocol. Minimize magic & sugar.
- Low number of dependencies. Only use stuff your system already has installed (ex: OpenSSL).
- Be friendly to proxies.
- Support enterprise deployments (ex: SPNEGO, Kerberos, NTLM)
- Embeds into event loops for asynchronous networking (ex: libev)

