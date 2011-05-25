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

Planning
--------
Check out the wiki and the series of planning notes. The first phase is to dig
into the HTTP protocol and learn it well before we start pushing code. Feel free to contribute
if you are a HTTP guru or just open up RFC 2616 and start reading! :)

