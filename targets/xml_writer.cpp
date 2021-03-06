// $Id: xml_writer.cpp,v 1.23 2016/04/15 08:40:55 ist178122 Exp $ -*- c++ -*-
#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void zu::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  processSimple(node, lvl);
}

void zu::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  processSimple(node, lvl);
}

//---------------------------------------------------------------------------

inline void zu::xml_writer::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}
void zu::xml_writer::do_not_node(zu::not_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}
void zu::xml_writer::do_identity_node(zu::identity_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}
void zu::xml_writer::do_address_node(zu::address_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void zu::xml_writer::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}
void zu::xml_writer::do_indexation_node(zu::indexation_node * const node, int lvl) {
  //processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_and_node(zu::and_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_or_node(zu::or_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_lvalue_node(zu::lvalue_node * const node, int lvl) {
  /*CHECK_TYPES(_compiler, _symtab, node);
  processSimple(node, lvl);*/
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_assignment_node(zu::assignment_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 2);
  openTag("rvalue", lvl + 2);
  node->rvalue()->accept(this, lvl + 4);
  closeTag("rvalue", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_function_node(zu::function_node * const node, int lvl) {
  openTag(node, lvl);
  node->statements()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_break_node(zu::break_node * const node, int lvl) { //será assim?
	  openTag(node, lvl);
          node->accept(this, lvl + 2);
          closeTag(node, lvl);
}

void zu::xml_writer::do_continue_node(zu::continue_node * const node, int lvl) { //será assim?
	  openTag(node, lvl);
          node->accept(this, lvl + 2);
          closeTag(node, lvl);
}

void zu::xml_writer::do_return_node(zu::return_node * const node, int lvl) { //será assim?
	  openTag(node, lvl);
          node->accept(this, lvl + 2);
          closeTag(node, lvl);
}

void zu::xml_writer::do_print_node(zu::print_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
 }

//---------------------------------------------------------------------------

void zu::xml_writer::do_read_node(zu::read_node * const node, int lvl) {
  openTag(node, lvl);
  node->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_for_node(zu::for_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("init", lvl + 2);
  node->init()->accept(this, lvl + 4);
  closeTag("init", lvl + 2);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("incr", lvl + 2);
  node->incr()->accept(this, lvl + 4);
  closeTag("incr", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_if_node(zu::if_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_apply_node(zu::apply_node * const node, int lvl) {
  
}

void zu::xml_writer::do_if_else_node(zu::if_else_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}


void zu::xml_writer::do_zuidentifier_node(zu::zuidentifier_node * const node, int lvl) {
	//FIXME: Complete method
}
void zu::xml_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
	//FIXME: Complete method
}
void zu::xml_writer::do_block_node(zu::block_node * const node, int lvl) {
	openTag(node, lvl);
	if(node->declaration() != NULL) {
		openTag("declaration", lvl+2);
		node->declaration()->accept(this, lvl+4);
		closeTag("declaration", lvl+2);
	}
	if(node->instruction() != NULL) {
		openTag("instruction", lvl+2);
		node->instruction()->accept(this, lvl+4);
		closeTag("instruction", lvl+2);
	}
	closeTag(node, lvl);
}
void zu::xml_writer::do_memalloc_node(zu::memalloc_node * const node, int lvl) {
	processUnaryExpression(node, lvl);
}
void zu::xml_writer::do_funcall_node(zu::funcall_node * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<" << node->name() \
	     << " identifier='" << node->id() << "'" \
	     << ">" << std::endl;
	openTag("arguments", lvl+2);
	node->arguments()->accept(this, lvl+4);
	closeTag("arguments", lvl+2);
	closeTag(node, lvl);
}

void zu::xml_writer::do_functionDeclaration_node(zu::functionDeclaration_node * const node, int lvl) { 
	os() << std::string(lvl, ' ') << "<" << node->name() \
	     << " identifier='" << node->identifier() << "'" \
	     << " type='" << node->type() << "'" \
	     << " ispublic='" << node->publica() << "'";
	os() << ">" << std::endl;
	if(node->arguments() != NULL) {
		openTag("Arguments", lvl+2);
		node->arguments()->accept(this, lvl+4);
		closeTag("Arguments", lvl+2);
	}
	closeTag(node, lvl);
	}

void zu::xml_writer::do_functionDefinition_node(zu::functionDefinition_node * const node, int lvl) { 
	os() << std::string(lvl, ' ') << "<" << node->name() \
	     << " identifier='" << node->identifier() << "'" \
	     << " type='" << node->type() << "'" \
	     << " ispublic='" << node->publica() << "'" \
	     << ">" << std::endl;
	if(node->arguments() != NULL) {
		openTag("Arguments", lvl+2);
		node->arguments()->accept(this, lvl+4);
		closeTag("Arguments", lvl+2);
	}
	openTag("Literal", lvl+2);
	node->literal()->accept(this, lvl+4);
	closeTag("Literal", lvl+2);
	openTag("Instructions", lvl+2);
	node->instructions()->accept(this, lvl+4);
	closeTag("Instructions", lvl+2);
	closeTag(node, lvl);	
	}

void zu::xml_writer::do_variableDeclaration_node(zu::variableDeclaration_node * const node, int lvl) { 
		os() << std::string(lvl, ' ') << "<" << node->name() \
	     << " identifier='" << node->identifier() << "'" \
	     << " type='" << /*type2str(*/node->type() << "'" \
	     << " ispublic='" << node->ispublic() << "'" \
	     << " isconst='" << node->isconst() << "'" \
	     << ">" << std::endl;
	}
	
void zu::xml_writer::do_variableDefinition_node(zu::variableDefinition_node * const node, int lvl) { 
	//FIXME: Complete method
	}

void zu::xml_writer::do_expressionAsInstruction_node(zu::expressionAsInstruction_node * const node, int lvl) { 
	node->expression()->accept(this, lvl);
	}