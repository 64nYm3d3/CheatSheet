
[Bad Blacklisting](#Bad_Blacklisting)

## Bad Blacklisting <a name="Bad_Blacklisting"></a>

This issue with bad blacklisting, when people are aware of an attack patterm amd and use a blacklist-based filter in order too omit common patterns of input. While it might prevent some cases, for the most part its a novelty. Below are some examples:

- If `SELECT` is blocked, try `SeLeCt`
- If `or 1=1--` is blocked, try `or 2=2--`
- If `alert('xss')` is blocked, try `prompt('xss')`
