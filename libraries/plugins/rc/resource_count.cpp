
#include <steem/plugins/rc/resource_count.hpp>

#include <steem/protocol/operations.hpp>
#include <steem/protocol/transaction.hpp>

#define RC_DEFAULT_EXEC_COST 100000

namespace steem { namespace plugins { namespace rc {

using namespace steem::protocol;

struct exec_operation_visitor
{
   typedef int64_t result_type;

   exec_operation_visitor() {}

   int64_t operator()( const account_create_operation& )const                 { return  57700; }
   int64_t operator()( const account_create_with_delegation_operation& )const { return  57700; }
   int64_t operator()( const account_update_operation& )const                 { return  14000; }
   int64_t operator()( const account_witness_proxy_operation& )const          { return 117000; }
   int64_t operator()( const account_witness_vote_operation& )const           { return  23000; }
   int64_t operator()( const cancel_transfer_from_savings_operation& )const   { return  11500; }
   int64_t operator()( const change_recovery_account_operation & )const       { return  12000; }
   int64_t operator()( const claim_account_operation& )const                  { return  10000; }
   int64_t operator()( const claim_reward_balance_operation& )const           { return  50300; }
   int64_t operator()( const create_claimed_account_operation& )const         { return  57700; }
   int64_t operator()( const comment_operation& )const                        { return 114100; }
   int64_t operator()( const comment_options_operation& )const                { return  13200; }
   int64_t operator()( const convert_operation& )const                        { return  15700; }
   int64_t operator()( const custom_operation& )const                         { return 228000; }
   int64_t operator()( const custom_json_operation& )const                    { return 228000; }
   int64_t operator()( const custom_binary_operation& )const                  { return 228000; }
   int64_t operator()( const decline_voting_rights_operation& )const          { return   5300; }
   int64_t operator()( const delegate_vesting_shares_operation& )const        { return  19900; }
   int64_t operator()( const delete_comment_operation& )const                 { return  51100; }
   int64_t operator()( const escrow_approve_operation& )const                 { return   9900; }
   int64_t operator()( const escrow_dispute_operation& )const                 { return  11500; }
   int64_t operator()( const escrow_release_operation& )const                 { return  17200; }
   int64_t operator()( const escrow_transfer_operation& )const                { return  19100; }
   int64_t operator()( const feed_publish_operation& )const                   { return   6200; }
   int64_t operator()( const limit_order_cancel_operation& )const             { return   9600; }
   int64_t operator()( const limit_order_create_operation& )const             { return  31700; }
   int64_t operator()( const limit_order_create2_operation& )const            { return  31700; }
   int64_t operator()( const recover_account_operation& )const                { return      0; }
   int64_t operator()( const request_account_recovery_operation& )const       { return  54400; }
   int64_t operator()( const set_withdraw_vesting_route_operation& )const     { return  17900; }
   int64_t operator()( const transfer_from_savings_operation& )const          { return  17500; }
   int64_t operator()( const transfer_operation& )const                       { return   9600; }
   int64_t operator()( const transfer_to_savings_operation& )const            { return   6400; }
   int64_t operator()( const transfer_to_vesting_operation& )const            { return  44400; }
   int64_t operator()( const vote_operation& )const                           { return  26500; }
   int64_t operator()( const withdraw_vesting_operation& )const               { return  10400; }
   int64_t operator()( const witness_set_properties_operation& )const         { return   9500; }
   int64_t operator()( const witness_update_operation& )const                 { return   9500; }
   int64_t operator()( const pow_operation& )const                            { return      0; }
   int64_t operator()( const pow2_operation& )const                           { return      0; }
   int64_t operator()( const report_over_production_operation& )const         { return      0; }
   int64_t operator()( const reset_account_operation& )const                  { return      0; }
   int64_t operator()( const set_reset_account_operation& )const              { return      0; }

#ifdef STEEM_ENABLE_SMT
   int64_t operator()( const claim_reward_balance2_operation& )const          { return 0; }
   int64_t operator()( const smt_setup_operation& )const                      { return 0; }
   int64_t operator()( const smt_cap_reveal_operation& )const                 { return 0; }
   int64_t operator()( const smt_refund_operation& )const                     { return 0; }
   int64_t operator()( const smt_setup_emissions_operation& )const            { return 0; }
   int64_t operator()( const smt_set_setup_parameters_operation& )const       { return 0; }
   int64_t operator()( const smt_set_runtime_parameters_operation& )const     { return 0; }
   int64_t operator()( const smt_create_operation& )const                     { return 0; }
#endif

   int64_t operator()( const fill_convert_request_operation& )const           { return 0; }
   int64_t operator()( const author_reward_operation& )const                  { return 0; }
   int64_t operator()( const curation_reward_operation& )const                { return 0; }
   int64_t operator()( const comment_reward_operation& )const                 { return 0; }
   int64_t operator()( const liquidity_reward_operation& )const               { return 0; }
   int64_t operator()( const interest_operation& )const                       { return 0; }
   int64_t operator()( const fill_vesting_withdraw_operation& )const          { return 0; }
   int64_t operator()( const fill_order_operation& )const                     { return 0; }
   int64_t operator()( const shutdown_witness_operation& )const               { return 0; }
   int64_t operator()( const fill_transfer_from_savings_operation& )const     { return 0; }
   int64_t operator()( const hardfork_operation& )const                       { return 0; }
   int64_t operator()( const comment_payout_update_operation& )const          { return 0; }
   int64_t operator()( const return_vesting_delegation_operation& )const      { return 0; }
   int64_t operator()( const comment_benefactor_reward_operation& )const      { return 0; }
   int64_t operator()( const producer_reward_operation& )const                { return 0; }
   int64_t operator()( const clear_null_account_balance_operation& )const     { return 0; }
};

struct count_operation_visitor
{
   typedef void result_type;

   mutable int32_t market_op_count = 0;
   mutable int32_t new_account_op_count = 0;

   count_operation_visitor() {}

   template< typename OpType >
   void operator()( const OpType op )const {}

   void operator()( const limit_order_create_operation& )const
   { market_op_count++; }
   void operator()( const limit_order_cancel_operation& )const
   { market_op_count++; }
   void operator()( const transfer_operation& )const
   { market_op_count++; }
   void operator()( const transfer_to_vesting_operation& )const
   { market_op_count++; }

   void operator()( const account_create_operation& op )const
   { new_account_op_count++; }
   void operator()( const account_create_with_delegation_operation& op )const
   { new_account_op_count++; }

   // TODO:
   // Should following ops be market ops?
   // withdraw_vesting, convert, set_withdraw_vesting_route, limit_order_create2
   // escrow_transfer, escrow_dispute, escrow_release, escrow_approve,
   // transfer_to_savings, transfer_from_savings, cancel_transfer_from_savings,
   // claim_reward_balance, delegate_vesting_shares, any SMT operations
};

void count_resources(
   const signed_transaction& tx,
   count_resources_result& result )
{
   const int64_t tx_size = int64_t( fc::raw::pack_size( tx ) );
   count_operation_visitor count_vtor;
   exec_operation_visitor exec_vtor;

   result.resource_count[ resource_history_bytes ] += tx_size;

   for( const operation& op : tx.operations )
   {
      op.visit( count_vtor );
      result.resource_count[ resource_execution_time ] += op.visit( exec_vtor );
   }

   result.resource_count[ resource_new_accounts ] += count_vtor.new_account_op_count;

   if( count_vtor.market_op_count > 0 )
      result.resource_count[ resource_market_bytes ] += tx_size;
}

} } } // steem::plugins::rc
