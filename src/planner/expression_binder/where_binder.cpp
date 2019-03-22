#include "planner/expression_binder/where_binder.hpp"

using namespace duckdb;
using namespace std;

WhereBinder::WhereBinder(Binder &binder, ClientContext &context) : ExpressionBinder(binder, context) {
}

BindResult WhereBinder::BindExpression(ParsedExpression &expr, uint32_t depth, bool root_expression) {
	switch (expr.GetExpressionClass()) {
	case ExpressionClass::AGGREGATE:
		return BindResult("WHERE clause cannot contain aggregates!");
	case ExpressionClass::DEFAULT:
		return BindResult("WHERE clause cannot contain DEFAULT clause");
	case ExpressionClass::WINDOW:
		return BindResult("WHERE clause cannot contain window functions!");
	default:
		return ExpressionBinder::BindExpression(expr, depth);
	}
}
