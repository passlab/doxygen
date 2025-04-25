static const char *stateToString(int state)
{
  switch(state)
  {
    case INITIAL: return "INITIAL";
    case Start: return "Start";
    case Command: return "Command";
    case SkipCommand: return "SkipCommand";
    case SkipLine: return "SkipLine";
    case SkipString: return "SkipString";
    case CopyLine: return "CopyLine";
    case LexCopyLine: return "LexCopyLine";
    case CopyString: return "CopyString";
    case CopyStringCs: return "CopyStringCs";
    case CopyStringFtn: return "CopyStringFtn";
    case CopyStringFtnDouble: return "CopyStringFtnDouble";
    case CopyRawString: return "CopyRawString";
    case Include: return "Include";
    case IncludeID: return "IncludeID";
    case EndImport: return "EndImport";
    case DefName: return "DefName";
    case DefineArg: return "DefineArg";
    case DefineText: return "DefineText";
    case CmakeDefName01: return "CmakeDefName01";
    case SkipCPPBlock: return "SkipCPPBlock";
    case SkipCComment: return "SkipCComment";
    case ArgCopyCComment: return "ArgCopyCComment";
    case ArgCopyCppComment: return "ArgCopyCppComment";
    case CopyCComment: return "CopyCComment";
    case SkipVerbatim: return "SkipVerbatim";
    case SkipCondVerbatim: return "SkipCondVerbatim";
    case SkipCPPComment: return "SkipCPPComment";
    case JavaDocVerbatimCode: return "JavaDocVerbatimCode";
    case RemoveCComment: return "RemoveCComment";
    case RemoveCPPComment: return "RemoveCPPComment";
    case Guard: return "Guard";
    case DefinedExpr1: return "DefinedExpr1";
    case DefinedExpr2: return "DefinedExpr2";
    case SkipDoubleQuote: return "SkipDoubleQuote";
    case SkipSingleQuote: return "SkipSingleQuote";
    case UndefName: return "UndefName";
    case IgnoreLine: return "IgnoreLine";
    case FindDefineArgs: return "FindDefineArgs";
    case ReadString: return "ReadString";
    case CondLineC: return "CondLineC";
    case CondLineCpp: return "CondLineCpp";
    case SkipCond: return "SkipCond";
    case IDLquote: return "IDLquote";
    case RulesPattern: return "RulesPattern";
    case RulesDouble: return "RulesDouble";
    case RulesRoundDouble: return "RulesRoundDouble";
    case RulesSquare: return "RulesSquare";
    case RulesRoundSquare: return "RulesRoundSquare";
    case RulesRound: return "RulesRound";
    case RulesRoundQuest: return "RulesRoundQuest";
    case PragmaOnce: return "PragmaOnce";
  }
  return "Unknown";
}
