static const char *stateToString(int state)
{
  switch(state)
  {
    case INITIAL: return "INITIAL";
    case Scan: return "Scan";
    case SkipString: return "SkipString";
    case SkipVerbString: return "SkipVerbString";
    case SkipChar: return "SkipChar";
    case SComment: return "SComment";
    case CComment: return "CComment";
    case CNComment: return "CNComment";
    case Verbatim: return "Verbatim";
    case VerbatimCode: return "VerbatimCode";
    case ReadLine: return "ReadLine";
    case CopyLine: return "CopyLine";
    case CondLine: return "CondLine";
    case ReadAliasArgs: return "ReadAliasArgs";
    case IncludeDoc: return "IncludeDoc";
    case SnippetDoc: return "SnippetDoc";
    case SnippetDocTag: return "SnippetDocTag";
    case IncludeFile: return "IncludeFile";
  }
  return "Unknown";
}
