///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.1).
//  The original source file is "..\..\prop-src\codegen.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "../../prop-src/codegen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the low level routine for generating C++ output->
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <AD/strings/charesc.h>
#include "codegen.h"
#include "ir.h"
#include "ast.h"
#include "type.h"
#include "matchcom.h"
#include "options.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Code generator constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////

CodeGen:: CodeGen()
    : output(&std::cerr), anchored(true), tabbing(0), tab_unit(2) {}
CodeGen::~CodeGen() {}

void CodeGen::set_stream(std::ostream& s) { output = &s; }

///////////////////////////////////////////////////////////////////////////////
//
//  Convert literals to a type string.
//
///////////////////////////////////////////////////////////////////////////////

#line 36 "../../prop-src/codegen.pcc"
#line 43 "../../prop-src/codegen.pcc"
Id literal_type_of (Literal x_1);
Id literal_type_of (Literal x_1)
{
  switch (x_1->tag__) {
    case a_Literal::tag_INTlit: {
#line 36 "../../prop-src/codegen.pcc"
     return "integer"; 
#line 36 "../../prop-src/codegen.pcc"
      } break;
    case a_Literal::tag_BOOLlit: {
#line 39 "../../prop-src/codegen.pcc"
     return "boolean"; 
#line 39 "../../prop-src/codegen.pcc"
      } break;
    case a_Literal::tag_CHARlit: {
#line 38 "../../prop-src/codegen.pcc"
     return "character"; 
#line 38 "../../prop-src/codegen.pcc"
      } break;
    case a_Literal::tag_REALlit: {
#line 37 "../../prop-src/codegen.pcc"
     return "real"; 
#line 37 "../../prop-src/codegen.pcc"
      } break;
    case a_Literal::tag_QUARKlit: {
#line 41 "../../prop-src/codegen.pcc"
     return "Quark"; 
#line 41 "../../prop-src/codegen.pcc"
      } break;
    case a_Literal::tag_BIGINTlit: {
#line 42 "../../prop-src/codegen.pcc"
     return "BigInt"; 
#line 42 "../../prop-src/codegen.pcc"
      } break;
    default: {
#line 40 "../../prop-src/codegen.pcc"
     return "string"; 
#line 40 "../../prop-src/codegen.pcc"
      } break;
  }
}
#line 43 "../../prop-src/codegen.pcc"
#line 43 "../../prop-src/codegen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Emit a string with indenting.
//
///////////////////////////////////////////////////////////////////////////////

void CodeGen::gen_code(const char * code)
{
  const char * p, * q;
  int line_no = 1;
  int my_tab = -1;
  for (p = code; *p; )
  {
    if (anchored)
    {
      int t;
      if (line_no == 2)
      {
        if (tabbing == 0)
          my_tab = 0;
        else
          for (my_tab = 0, q = p; *q == ' '; q++)
            my_tab++;
      }
      if (line_no >= 2)
      {
        for (t = my_tab; *p == ' ' && t > 0; p++) t--;
        for (t = tabbing; t > 0; t--) output->put(' ');
      }
      else
      {
        for (t = tabbing; *p == ' ' && t > 0; p++)
          t--;
        for ( ; t > 0; t--)
          output->put(' ');
      }
    }
    else
    {
      for ( ; *p == ' '; p++);
      output->put(' ');
    }
    anchored = false;
    for (;;)
    {
      if (*p == '\0')
        break;
      output->put(*p);
      if (*p == '\n')
        { line_no++; anchored = true; p++; break; }
      p++;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Decode a format string and dispatch to various printing routines.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& CodeGen::outv( const char * fmt, std::va_list arg)
{
  unsigned char c;
  while ((c = *fmt++) != 0)
  {
    if (c == '%')
    {
      switch (*fmt++)
      {
      case 'i':
        {
          (*output) << va_arg(arg,int);
          anchored = false;
          break;
        }
      case 'c':
        {
          c = (unsigned char) va_arg( arg, int);
          output->put(c);
          anchored = (c == '\n');
          break;
        }
      case 'C':
        {
          gen_code( va_arg( arg, const char *));
          break;
        }
      case 's':
        {
          const char * s = va_arg( arg, const char *);
          int len = std::strlen(s);
          (*output) << s;
          anchored = (s[len-1] == '\n');
        }
        break;
      case 'S':
        {
          (*output) << mangle( va_arg( arg, const char *));
          anchored = false;
          break;
        }
      case 'q':
        {
          (*output) << va_arg( arg, QualId);
          anchored = false;
          break;
        }
      case 'e':
        {
          (*output) << va_arg( arg, Exp);
          anchored = false;
          break;
        }
    case 'f':
      {
        Bool save = pretty_print_exp;
      pretty_print_exp = true;
          (*output)<< va_arg(arg,Exp);
          anchored = false;
      pretty_print_exp = save;
        break;
      }
      case 'E':
        {
          Exp e = va_arg( arg, Exp);
          
#line 171 "../../prop-src/codegen.pcc"
#line 176 "../../prop-src/codegen.pcc"
{
  if (e) {
    switch (e->tag__) {
      case a_Exp::tag_MARKEDexp: {
#line 174 "../../prop-src/codegen.pcc"
       pr ("%D", MARKEDdecl( ((Exp_MARKEDexp *)e)->_1, EXPdecl(((Exp_MARKEDexp *)e)->_2))); 
#line 174 "../../prop-src/codegen.pcc"
        } break;
      default: {
        L1:; 
#line 176 "../../prop-src/codegen.pcc"
        (*output)<< e; 
#line 176 "../../prop-src/codegen.pcc"
        } break;
    }
  } else { goto L1; }
}
#line 177 "../../prop-src/codegen.pcc"
#line 177 "../../prop-src/codegen.pcc"

          anchored = false;
          break;
        }
      case 'l':
        {
          (*output) << va_arg( arg, Literal);
          anchored = false;
          break;
        }
      case 'p':
        {
          (*output) << va_arg( arg, Pat);
          anchored = false;
          break;
        }
      case 'r':
        {
          (*output) << va_arg( arg, MatchRule);
          anchored = false;
          break;
        }
      case 'b':
        {
          Ty ty = va_arg( arg, Ty);
          Id        name     = va_arg( arg, Id);
          Id        id       = mangle( name);
          Parameter p        = (Parameter) va_arg( arg, int);
          Bool      is_array = is_array_constructor( name);
          if (is_array)
          {
            Ty body_ty = NOty;
            if (p == TYbody)
            {
              pr ("%^const int len_;%^");
              body_ty = mkarrayty( ty, LITERALexp( INTlit(0)));
            }
            else
            {
              body_ty =
                mkrecordty(
                
#line 218 "../../prop-src/codegen.pcc"
#line 218 "../../prop-src/codegen.pcc"
list_1_(Id("_len_"),list_1_(id))
#line 218 "../../prop-src/codegen.pcc"
#line 218 "../../prop-src/codegen.pcc"
,
                
#line 219 "../../prop-src/codegen.pcc"
#line 219 "../../prop-src/codegen.pcc"
list_1_(integer_ty,list_1_(mkptrty(QUALty(QUALconst,ty))))
#line 219 "../../prop-src/codegen.pcc"
#line 219 "../../prop-src/codegen.pcc"
,
                false);
            }
            print_parameter( *output, body_ty, id, p);
            if (p == TYbody)
            {
              pr(
                  "\n"
                  "%^inline int len() const { return len_; }"
                  "%^inline %t const&  at(int i) const { return %S[i]; }"
                  "%^inline %t&        at(int i)       { return %S[i]; }"
                  "%^inline %t const * array() const   { return %S; }"
                  "%^inline %t *       array()         { return %S; }",
                  ty, "", name, ty, "", name,
                  ty, "", name, ty, "", name
                );
            }
          }
          else
             print_parameter( *output, ty, id, p);
          anchored = false;
        }
        break;
      case 'T':
        {
          (*output) << va_arg( arg,Ty);
          anchored = false;
          break;
        }
      case 't':
        {
          Bool save = pretty_print_ty;
          pretty_print_ty = false;
          Ty ty = va_arg( arg, Ty);
          ty_id = va_arg( arg, Id);
          (*output) << ty;
          anchored = false;
          pretty_print_ty = save;
          break;
        }
      case 'V':
        {
          print_tyvars( *output, va_arg( arg, TyVars), '<', '>', false);
          anchored = false;
          break;
        }
      case 'P':
        {
          Tys tys = va_arg( arg, Tys);
          Bool save = pretty_print_ty;
          pretty_print_ty = false;
          if (tys)(*output) << '<' << tys << '>';
          pretty_print_ty = save;
          anchored = false;
        }
        break;
      case 'Q':
        {
          (*output) << va_arg( arg, Pid);
          anchored = false;
          break;
        }
      case 'H':
        {
          print_tyvars( *output, va_arg( arg, TyVars), '<', '>', true);
          anchored = false;
          break;
        }
      case 'v':
        {
          print_tyvars( *output, va_arg( arg, TyVars), '(', ')', false);
          anchored = false;
          break;
        }
      case '#':
        {
          int l = va_arg( arg, int);
          const char * f = va_arg( arg, const char *);
          if (options.line_directives)
          {
            if (! anchored)
              (*output) << '\n';
#ifdef _MSC_VER
            char *filename = new char[ strlen( f) + 1];

            const char *s = f;
            char *d = filename;

            for ( ; *s != '\0'; ++s, ++d)
              if ( *s != '\\')
                *d = *s;
              else
                *d = '/';
            *d = '\0';

            (*output) << "#line " << l << " \"" << filename << "\"\n";

            delete filename;
#else
            (*output)<< "#line " << l << " \"" << f << "\"\n";
#endif
            anchored = true;
          }
        }
        break;
      case '!':
        {
          const Loc * l = va_arg( arg, const Loc *);
          if (! anchored)(*output) << '\n';
          if (options.GNU_style_message)
            (*output)<< l->file_name << ':'
                    << l->begin_line << ": ";
          else
            (*output)<< '"' << l->file_name << "\", line "
                    << l->begin_line << ": ";
          anchored = true;
        }  break;
      case 'L':
        {
          if (options.GNU_style_message)
            (*output) << file << ':' << line << ": ";
          else
            (*output) << '"' << file << "\", line " << line << ": ";
          anchored = false;
          break;
        }
      case 'w':
        {
          if (options.strict_checking)
            errors++;
          else
            (*output) << "warning: ";
          anchored = false;
          break;
        }
      case 'M':
        {
          (*output) << va_arg( arg, Match);
          anchored = false;
          break;
        }
      case 'n':
        {
          if (! anchored)
            (*output) << '\n';
          anchored = true;
          break;
        }
      case 'I':
        {
          Inherits i = va_arg( arg, Inherits);
          (*output) << i;
          anchored = false;
          break;
        }
      case 'U':
        {
          Exp exp = va_arg(arg,Exp);
      Ty  ty  = va_arg(arg,Ty);
      (*output) << MatchCompiler::untag( exp, ty);
          break;
        }
      case '*':
        {
          Cons cons = va_arg(arg,Cons);
      Bool normalized = (Bool) va_arg( arg, int);
      (*output) << MatchCompiler::tag_name_of( cons, normalized);
          break;
        }
      case '%':
        {
          (*output) << '%';
          anchored = false;
          break;
        }
      case '?':
        {
          if (! anchored)
            break;
        }
      case '^':
        {
          if (! anchored)
            (*output) << '\n';
          if (tabbing < 0)
            error ("Tab = %i\n", tabbing);
          for (int i = tabbing; i > 0; i--)
            (*output) << ' ';
          anchored = (tabbing == 0);
          break;
        }
      case '+':
        {
          tabbing += tab_unit;
          break;
        }
      case '-':
        {
          tabbing -= tab_unit;
          break;
        }
      case '/':
        {
          for (int i = 79 - tabbing; i > 0; i--)
            (*output) << '/';
          (*output) << '\n'; anchored = true;
          break;
        }
      case '=':
        {
          (*output) << "_equal_" << literal_type_of( va_arg( arg, Literal));
          break;
        }
      case '<':
        {
          (*output) << "_less_"  << literal_type_of( va_arg( arg, Literal));
          break;
        }
      default:
        {
          arg = printer( fmt[-1], arg);
          break;
        }
      }
    }
    else
    {
    output->put(c);
    anchored = (c == '\n');
    }
  }
  return *output;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Entry point.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& CodeGen::pr( const char * fmt, ...)
{
  std::va_list arg;
  va_start( arg, fmt);
  outv( fmt, arg);
  va_end( arg);
  return *output;
}
#line 467 "../../prop-src/codegen.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 37
Number of ifs generated      = 1
Number of switches generated = 2
Number of labels             = 1
Number of gotos              = 1
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
