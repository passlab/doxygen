#include <string.h>
#include <version.h>

/* - On some systems git is not installed or
 *   installed on a place where FindGit.cmake cannot find it
 * - No git information is present (no .git directory)
 * in those cases clear the gitVersionString (would have string GIT-NOTFOUND).
 */
std::string getGitVersion()
{
  static std::string gitVersion;
  static bool init = false;
  if (!init)
  {
    gitVersion = "4d77f3fb806ad4bd8130e9fab09f9d3a4f58573b";
    if (std::string("true")=="true")
    {
      gitVersion+="*";
    }
    if (gitVersion=="GIT-NOTFOUND")
    {
      gitVersion="";
    }
    init = true;
  }
  return gitVersion;
}
