///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "setl-ast.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "setl-ast.ph"
///////////////////////////////////////////////////////////////////////////////
//
//  This file contains the abstract syntax tree definitions for the
//  SETL-like extension language of Prop.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef setl_extension_abstract_syntax_tree_h
#define setl_extension_abstract_syntax_tree_h

#include <iostream>
#include "basics.h"
#include "ir.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Forward AST declarations.
//
///////////////////////////////////////////////////////////////////////////////

#line 22 "setl-ast.ph"
#line 26 "setl-ast.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Exp
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Exp_defined
#define datatype_Exp_defined
  class a_Exp;
  typedef a_Exp * Exp;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Decl
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Decl_defined
#define datatype_Decl_defined
  class a_Decl;
  typedef a_Decl * Decl;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Time
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Time_defined
#define datatype_Time_defined
  class a_Time;
  typedef a_Time * Time;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Space
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Space_defined
#define datatype_Space_defined
  class a_Space;
  typedef a_Space * Space;
#endif

#line 26 "setl-ast.ph"
#line 26 "setl-ast.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  AST for definitions, signatures, statements and bindings
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Type 'Def' represents definitions.
//
///////////////////////////////////////////////////////////////////////////////

#line 40 "setl-ast.ph"
#line 116 "setl-ast.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Def
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Def_defined
#define datatype_Def_defined
  class a_Def;
  typedef a_Def * Def;
#endif

#  define NOdef 0

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Sig
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Sig_defined
#define datatype_Sig_defined
  class a_Sig;
  typedef a_Sig * Sig;
#endif

#  define NOsig 0

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Stmt
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Stmt_defined
#define datatype_Stmt_defined
  class a_Stmt;
  typedef a_Stmt * Stmt;
#endif

#  define NOstmt 0

///////////////////////////////////////////////////////////////////////////////
// Definition of type LabSig
///////////////////////////////////////////////////////////////////////////////
#line 110 "setl-ast.ph"
typedef struct { Id id; Sig sig;  } LabSig;

///////////////////////////////////////////////////////////////////////////////
// Definition of type LabSigs
///////////////////////////////////////////////////////////////////////////////
#line 111 "setl-ast.ph"
typedef a_List<LabSig> *  LabSigs;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Defs
///////////////////////////////////////////////////////////////////////////////
#line 112 "setl-ast.ph"
typedef a_List<Def> *  Defs;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Sigs
///////////////////////////////////////////////////////////////////////////////
#line 113 "setl-ast.ph"
typedef a_List<Sig> *  Sigs;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Stmts
///////////////////////////////////////////////////////////////////////////////
#line 114 "setl-ast.ph"
typedef a_List<Stmt> *  Stmts;

///////////////////////////////////////////////////////////////////////////////
// Definition of type Generators
///////////////////////////////////////////////////////////////////////////////
#line 115 "setl-ast.ph"
typedef a_List<Generator> *  Generators;

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Def
//
///////////////////////////////////////////////////////////////////////////////
class a_Def : public Loc {
public:
  enum Tag_Def {
    tag_VARdef = 0, tag_FUNCTIONdef = 1, tag_MODULEdef = 2, 
    tag_SIGNATUREdef = 3, tag_TYPEdef = 4, tag_LAMBDAdef = 5
  };

public:
  const Tag_Def tag__; // variant tag
protected:
  inline a_Def(Tag_Def t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Def * x) { return x != 0; }
inline int untag(const a_Def * x) { return x ? (x->tag__+1) : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Def::VARdef
//
///////////////////////////////////////////////////////////////////////////////
class Def_VARdef : public a_Def {
public:
#line 42 "setl-ast.ph"
  Id id; Ty ty; Exp init_exp; 
  Def_VARdef (Id x_id, Ty x_ty, Exp x_init_exp = NOexp);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Def::FUNCTIONdef
//
///////////////////////////////////////////////////////////////////////////////
class Def_FUNCTIONdef : public a_Def {
public:
#line 48 "setl-ast.ph"
  Id id; LabTys args; Ty return_ty; Defs local_defs; Stmts body; 
  Def_FUNCTIONdef (Id x_id, LabTys x_args, Ty x_return_ty, Defs x_local_defs, Stmts x_body);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Def::MODULEdef
//
///////////////////////////////////////////////////////////////////////////////
class Def_MODULEdef : public a_Def {
public:
#line 56 "setl-ast.ph"
  Id id; LabSigs args; Sig sig; Defs body; 
  Def_MODULEdef (Id x_id, LabSigs x_args, Sig x_sig, Defs x_body);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Def::SIGNATUREdef
//
///////////////////////////////////////////////////////////////////////////////
class Def_SIGNATUREdef : public a_Def {
public:
#line 63 "setl-ast.ph"
  Id id; LabSigs args; Sig sig; 
  Def_SIGNATUREdef (Id x_id, LabSigs x_args, Sig x_sig);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Def::TYPEdef
//
///////////////////////////////////////////////////////////////////////////////
class Def_TYPEdef : public a_Def {
public:
#line 69 "setl-ast.ph"
  Decl TYPEdef; 
  Def_TYPEdef (Decl x_TYPEdef);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Def::LAMBDAdef
//
///////////////////////////////////////////////////////////////////////////////
class Def_LAMBDAdef : public a_Def {
public:
#line 70 "setl-ast.ph"
  LabTys _1; Defs _2; 
  Def_LAMBDAdef (LabTys x_1, Defs x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Def
//
///////////////////////////////////////////////////////////////////////////////
extern a_Def * VARdef (Id x_id, Ty x_ty, Exp x_init_exp = NOexp);
extern a_Def * FUNCTIONdef (Id x_id, LabTys x_args, Ty x_return_ty, Defs x_local_defs, Stmts x_body);
extern a_Def * MODULEdef (Id x_id, LabSigs x_args, Sig x_sig, Defs x_body);
extern a_Def * SIGNATUREdef (Id x_id, LabSigs x_args, Sig x_sig);
extern a_Def * TYPEdef (Decl x_TYPEdef);
extern a_Def * LAMBDAdef (LabTys x_1, Defs x_2);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Sig
//
///////////////////////////////////////////////////////////////////////////////
class a_Sig : public Loc {
public:
  enum Tag_Sig {
    tag_IDsig = 0, tag_DOTsig = 1, tag_APPsig = 2, 
    tag_DEFsig = 3, tag_LAMBDAsig = 4
  };

public:
  const Tag_Sig tag__; // variant tag
protected:
  inline a_Sig(Tag_Sig t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Sig * x) { return x != 0; }
inline int untag(const a_Sig * x) { return x ? (x->tag__+1) : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Sig::IDsig
//
///////////////////////////////////////////////////////////////////////////////
class Sig_IDsig : public a_Sig {
public:
#line 80 "setl-ast.ph"
  Id IDsig; 
  Sig_IDsig (Id x_IDsig);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Sig::DOTsig
//
///////////////////////////////////////////////////////////////////////////////
class Sig_DOTsig : public a_Sig {
public:
#line 81 "setl-ast.ph"
  Sig _1; Id _2; 
  Sig_DOTsig (Sig x_1, Id x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Sig::APPsig
//
///////////////////////////////////////////////////////////////////////////////
class Sig_APPsig : public a_Sig {
public:
#line 82 "setl-ast.ph"
  Sig _1; Sigs _2; 
  Sig_APPsig (Sig x_1, Sigs x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Sig::DEFsig
//
///////////////////////////////////////////////////////////////////////////////
class Sig_DEFsig : public a_Sig {
public:
#line 83 "setl-ast.ph"
  Defs DEFsig; 
  Sig_DEFsig (Defs x_DEFsig);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Sig::LAMBDAsig
//
///////////////////////////////////////////////////////////////////////////////
class Sig_LAMBDAsig : public a_Sig {
public:
#line 84 "setl-ast.ph"
  LabSigs _1; Sig _2; 
  Sig_LAMBDAsig (LabSigs x_1, Sig x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Sig
//
///////////////////////////////////////////////////////////////////////////////
extern a_Sig * IDsig (Id x_IDsig);
extern a_Sig * DOTsig (Sig x_1, Id x_2);
extern a_Sig * APPsig (Sig x_1, Sigs x_2);
extern a_Sig * DEFsig (Defs x_DEFsig);
extern a_Sig * LAMBDAsig (LabSigs x_1, Sig x_2);

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Stmt
//
///////////////////////////////////////////////////////////////////////////////
class a_Stmt : public Loc {
public:
  enum Tag_Stmt {
    tag_ASSIGNstmt = 0, tag_BLOCKstmt = 1, tag_WHILEstmt = 2, 
    tag_IFstmt = 3, tag_MATCHstmt = 4, tag_REWRITEstmt = 5, 
    tag_REPLACEMENTstmt = 6, tag_FORALLstmt = 7, tag_RETURNstmt = 8
  };

public:
  const Tag_Stmt tag__; // variant tag
protected:
  inline a_Stmt(Tag_Stmt t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Stmt * x) { return x != 0; }
inline int untag(const a_Stmt * x) { return x ? (x->tag__+1) : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::ASSIGNstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_ASSIGNstmt : public a_Stmt {
public:
#line 94 "setl-ast.ph"
  Exp _1; Exp _2; 
  Stmt_ASSIGNstmt (Exp x_1, Exp x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::BLOCKstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_BLOCKstmt : public a_Stmt {
public:
#line 95 "setl-ast.ph"
  Defs _1; Stmts _2; 
  Stmt_BLOCKstmt (Defs x_1, Stmts x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::WHILEstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_WHILEstmt : public a_Stmt {
public:
#line 96 "setl-ast.ph"
  Exp _1; Stmt _2; 
  Stmt_WHILEstmt (Exp x_1, Stmt x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::IFstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_IFstmt : public a_Stmt {
public:
#line 97 "setl-ast.ph"
  Exp _1; Stmt _2; Stmt _3; 
  Stmt_IFstmt (Exp x_1, Stmt x_2, Stmt x_3);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::MATCHstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_MATCHstmt : public a_Stmt {
public:
#line 98 "setl-ast.ph"
  Decl MATCHstmt; 
  Stmt_MATCHstmt (Decl x_MATCHstmt);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::REWRITEstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_REWRITEstmt : public a_Stmt {
public:
#line 99 "setl-ast.ph"
  Decl REWRITEstmt; 
  Stmt_REWRITEstmt (Decl x_REWRITEstmt);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::REPLACEMENTstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_REPLACEMENTstmt : public a_Stmt {
public:
#line 100 "setl-ast.ph"
  Decl REPLACEMENTstmt; 
  Stmt_REPLACEMENTstmt (Decl x_REPLACEMENTstmt);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::FORALLstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_FORALLstmt : public a_Stmt {
public:
#line 101 "setl-ast.ph"
  Generators _1; Stmt _2; 
  Stmt_FORALLstmt (Generators x_1, Stmt x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Stmt::RETURNstmt
//
///////////////////////////////////////////////////////////////////////////////
class Stmt_RETURNstmt : public a_Stmt {
public:
#line 102 "setl-ast.ph"
  Exp RETURNstmt; 
  Stmt_RETURNstmt (Exp x_RETURNstmt);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Stmt
//
///////////////////////////////////////////////////////////////////////////////
extern a_Stmt * ASSIGNstmt (Exp x_1, Exp x_2);
extern a_Stmt * BLOCKstmt (Defs x_1, Stmts x_2);
extern a_Stmt * WHILEstmt (Exp x_1, Stmt x_2);
extern a_Stmt * IFstmt (Exp x_1, Stmt x_2, Stmt x_3);
extern a_Stmt * MATCHstmt (Decl x_MATCHstmt);
extern a_Stmt * REWRITEstmt (Decl x_REWRITEstmt);
extern a_Stmt * REPLACEMENTstmt (Decl x_REPLACEMENTstmt);
extern a_Stmt * FORALLstmt (Generators x_1, Stmt x_2);
extern a_Stmt * RETURNstmt (Exp x_RETURNstmt);

#line 116 "setl-ast.ph"
#line 116 "setl-ast.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing routines for definitions, statements and generators
//
///////////////////////////////////////////////////////////////////////////////

extern std::ostream& operator << (std::ostream&, Def);
extern std::ostream& operator << (std::ostream&, Defs);
extern std::ostream& operator << (std::ostream&, Sig);
extern std::ostream& operator << (std::ostream&, Sigs);
extern std::ostream& operator << (std::ostream&, Stmt);
extern std::ostream& operator << (std::ostream&, Stmts);
extern std::ostream& operator << (std::ostream&, LabSig);
extern std::ostream& operator << (std::ostream&, LabSigs);
extern std::ostream& operator << (std::ostream&, Generator);
extern std::ostream& operator << (std::ostream&, Generators);

#endif
#line 136 "setl-ast.ph"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
