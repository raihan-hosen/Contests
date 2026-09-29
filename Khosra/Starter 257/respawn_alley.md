# RESPawn Alley 2.0

## Production-Grade Free Fire Custom Match & Tournament Platform

---

# 1. PROJECT OVERVIEW

RESPawn Alley is a gaming platform focused on Free Fire custom matches and tournaments.

The platform allows players to:

- Create an account
- Maintain a wallet
- Deposit money
- Receive promotional credits
- Join Solo, Duo, and Squad matches
- Pay entry fees
- Receive room information when released
- Participate in matches
- Receive winnings/refunds where applicable
- Withdraw eligible funds
- Refer other players
- Receive referral rewards
- Participate in promotional campaigns
- Receive notifications
- View match history
- View transaction history

The platform also provides an administrative system where authorized staff can:

- Create and manage matches
- Configure match templates
- Release room information
- Manage users
- Manage withdrawals
- Monitor payments
- Manage promotional campaigns
- Manage referrals
- Manage platform configuration
- Manage moderators/admin permissions
- Monitor platform activity

The platform must be designed as a serious production application.

Do NOT treat this as a simple CRUD project.

Financial operations, authentication, authorization, concurrency, payment verification, and auditability are critical.

---

# 2. IMPORTANT DEVELOPMENT PRINCIPLE

This project is a REBUILD.

There was a previous PHP + MySQL implementation.

The new application MUST NOT blindly copy the old PHP architecture.

Use the previous application's business requirements as functional requirements, but implement the new system using a modern architecture.

The new application is:

RESPawn Alley 2.0

The old application should be considered a reference for:

- Business rules
- Existing functionality
- User flows
- Existing terminology
- Match logic
- Wallet behavior
- Payment behavior

The new implementation should improve:

- Security
- Scalability
- Maintainability
- Database consistency
- Code organization
- Testing
- Error handling
- Developer experience
- API architecture
- Observability

---

# 3. TECHNOLOGY STACK

Use the following stack unless there is a very strong technical reason to change something.

## Frontend

- Next.js
- React
- TypeScript
- App Router
- Tailwind CSS
- shadcn/ui where appropriate
- TanStack Query for server state
- React Hook Form
- Zod
- Lucide icons

## Backend

- Node.js
- TypeScript
- Express.js

Backend architecture must be modular.

Do NOT put the entire application inside one server.js file.

## Database

Primary database:

- PostgreSQL

Use:

- Prisma ORM

The database must use proper:

- Foreign keys
- Unique constraints
- Check constraints where appropriate
- Indexes
- Transactions
- Referential integrity

## Authentication

Use:

- Short-lived access tokens
- Refresh tokens
- Secure password hashing
- HTTP-only cookies where appropriate
- Role-based authorization

Use Argon2id or bcrypt for password hashing.

Never store plaintext passwords.

## Validation

Use:

- Zod

All external input must be validated.

Never trust:

- Request body
- Query parameters
- URL parameters
- Headers
- Cookies
- Client-side calculated values

## Real-time

Use:

- Socket.IO

for:

- Match status updates
- Room release notifications
- Live administrative updates
- Wallet-related notifications where useful
- Platform notifications

## Background Jobs

Use a proper job/queue architecture.

Preferred:

- BullMQ
- Redis

Jobs may handle:

- Match state transitions
- Scheduled notifications
- Payment reconciliation
- Expired payment sessions
- Promotional activation
- Automated maintenance

## API Documentation

Use OpenAPI/Swagger.

Every public API endpoint should eventually be documented.

## Testing

Use:

- Vitest or Jest
- Supertest
- Playwright

Testing must cover critical financial and authentication flows.

---

# 4. HIGH LEVEL ARCHITECTURE

Use a monorepo structure.

Recommended structure:

respawn-alley/

    apps/
        web/
        api/
        mobile/

    packages/
        database/
        types/
        validation/
        config/
        ui/

    infrastructure/
        docker/
        nginx/

    docs/

    scripts/

    package.json

    pnpm-workspace.yaml

    docker-compose.yml

    README.md

The exact structure can be adjusted if technically necessary, but maintain clear separation between:

- Frontend
- Backend
- Database
- Shared types
- Validation
- Infrastructure
- Documentation

---

# 5. FRONTEND ARCHITECTURE

The web application must use:

Next.js + React + TypeScript.

Use App Router.

Organize the frontend around feature/domain areas.

Example:

apps/web/

    app/
        (public)/
        (auth)/
        dashboard/
        matches/
        wallet/
        profile/
        referrals/
        promotions/
        notifications/
        admin/

    components/

    features/
        auth/
        matches/
        wallet/
        profile/
        referrals/
        promotions/
        notifications/
        admin/

    lib/

    hooks/

    services/

    types/

    validations/

Do not put all components in one giant components folder without organization.

---

# 6. BACKEND ARCHITECTURE

Backend:

Node.js + TypeScript + Express.

Use modular architecture.

Example:

apps/api/src/

    config/

    modules/
        auth/
        users/
        wallets/
        transactions/
        payments/
        matches/
        match-participants/
        withdrawals/
        referrals/
        promotions/
        notifications/
        admin/
        audit/

    middleware/

    jobs/

    services/

    utils/

    database/

    app.ts

    server.ts

Each major module should preferably contain:

- routes
- controller
- service
- repository/data access
- schema
- types
- tests

Business logic belongs in services.

Do NOT put important business rules directly inside route handlers.

---

# 7. DATABASE DESIGN PRINCIPLES

PostgreSQL is the source of truth.

The database must be designed for financial consistency.

Never rely only on frontend state for:

- Wallet balance
- Match availability
- Entry fee
- Withdrawal eligibility
- Payment status
- Referral eligibility

All important state must be validated server-side.

---

# 8. CORE DATABASE ENTITIES

The following entities are expected.

## Users

Fields should include approximately:

- id
- full_name
- username
- phone
- password_hash
- ff_uid
- ff_nickname
- avatar
- status
- created_at
- updated_at
- last_login_at

Username must be unique.

Phone must be unique if phone-based account identity is used.

Free Fire UID rules should be configurable.

---

# 9. ROLES

Support role-based access control.

Initial roles:

- PLAYER
- MODERATOR
- ADMIN
- SUPER_ADMIN

Do not use simple boolean flags such as:

isAdmin = true

for serious authorization.

Use role/permission based authorization.

---

# 10. PERMISSIONS

Create a permission system.

Examples:

MATCH_CREATE
MATCH_UPDATE
MATCH_DELETE
MATCH_ROOM_RELEASE
MATCH_COMPLETE

USER_VIEW
USER_UPDATE
USER_SUSPEND

WITHDRAWAL_VIEW
WITHDRAWAL_APPROVE
WITHDRAWAL_REJECT

PAYMENT_VIEW
PAYMENT_RECONCILE

PROMOTION_CREATE
PROMOTION_UPDATE
PROMOTION_DELETE

REFERRAL_VIEW
REFERRAL_MANAGE

ADMIN_MANAGE
ROLE_MANAGE

AUDIT_VIEW

SUPER_ADMIN should have all permissions.

Moderator permissions should be configurable.

---

# 11. WALLET ARCHITECTURE

This is one of the most important parts of the entire application.

DO NOT treat wallet_balance as the only source of truth.

Implement a transaction ledger.

A user should have:

- Cash balance
- Promotional balance

Both must be tracked independently.

---

# 12. WALLET LEDGER

Create a wallet transaction/ledger system.

Example transaction types:

DEPOSIT
ENTRY_FEE
WINNING
WITHDRAWAL
REFUND
REFERRAL_BONUS
PROMO_CREDIT
PROMO_USAGE
ADJUSTMENT
REVERSAL

Each transaction should contain information such as:

- id
- user_id
- wallet type
- transaction type
- amount
- balance_before
- balance_after
- reference_type
- reference_id
- status
- metadata
- created_at

Every financial change must be auditable.

---

# 13. WALLET CONCURRENCY

Wallet operations must be atomic.

Example:

User has:

Cash = 100
Promo = 5

Match entry fee = 20

The system should consume:

Promo = 5
Cash = 15

Final:

Cash = 85
Promo = 0

This operation must occur inside a database transaction.

Prevent:

- Double spending
- Race conditions
- Negative balances
- Duplicate transaction processing

Use appropriate PostgreSQL transaction isolation and row locking where necessary.

---

# 14. PROMOTIONAL BALANCE

Promotional balance is NOT withdrawable.

Promotional funds may be used for eligible match entry fees.

Promo balance must be clearly separated from withdrawable cash balance.

The frontend must clearly indicate:

- Cash balance
- Promo balance
- Withdrawable balance

Do not allow users to misunderstand promotional funds as cash.

---

# 15. NEW PLAYER PROMOTION

Existing business rule:

New player promotional reward:

৳5

However:

The reward should remain pending until the user completes their first eligible paid match.

After the condition is satisfied, the promotion becomes active.

The exact activation state must be stored.

Possible states:

PENDING
ACTIVE
USED
EXPIRED
CANCELLED

Do not simply add ৳5 directly to the wallet during registration.

---

# 16. REFERRAL SYSTEM

Referral reward:

৳10

Create a proper referral relationship.

Example:

referrer_id
referred_user_id
reward_amount
status
created_at
completed_at

Referral reward must be granted only when the defined eligibility condition is satisfied.

Prevent:

- Self referral
- Duplicate referral
- Referral manipulation
- Repeated reward claims

All rewards must create ledger entries.

---

# 17. MATCH SYSTEM

Support:

- Solo
- Duo
- Squad

A match should contain:

- id
- title/name
- type
- entry_fee
- max_players
- scheduled_at
- registration_open_at
- registration_close_at
- room_id
- room_password
- status
- template_id
- created_by
- created_at
- updated_at

---

# 18. MATCH STATUS

Use explicit match states.

Recommended:

DRAFT
UPCOMING
OPEN
FULL
ROOM_RELEASED
LIVE
COMPLETED
CANCELLED

The exact state machine must be enforced.

Invalid transitions must be rejected.

Example:

COMPLETED -> OPEN

must not be allowed.

---

# 19. MATCH PARTICIPATION

Create a match_participants table.

Fields may include:

- id
- match_id
- user_id
- team_id if required
- entry_fee_paid
- cash_used
- promo_used
- joined_at
- status
- result
- placement
- winnings

A user must not be able to join the same match twice.

Use database constraints to enforce this.

---

# 20. MATCH CAPACITY

If max_players = 48:

Only 48 eligible participants can join.

Capacity checks must happen inside a transaction.

Do not rely on:

frontend_count < max_players

because simultaneous requests can bypass this.

Use database-safe concurrency handling.

---

# 21. MATCH ENTRY FLOW

Example:

User opens match.

Server checks:

1. User authenticated
2. Account active
3. Match exists
4. Match is OPEN
5. Registration still available
6. Match not full
7. User not already participating
8. User has enough eligible funds
9. Entry fee is valid
10. Wallet transaction can be performed

Then inside one transaction:

- Reserve participant slot
- Deduct promo first
- Deduct cash remainder
- Create ledger transactions
- Create participant record

If any operation fails:

ROLLBACK EVERYTHING.

---

# 22. ROOM RELEASE

Room information should not be visible before release.

Admin can release:

- Room ID
- Room password

Once released:

- Match status becomes ROOM_RELEASED
- Eligible participants receive the information
- Real-time notification can be sent

Room credentials must not be publicly accessible.

---

# 23. MATCH COMPLETION

When a match ends:

Status becomes:

COMPLETED

Results can then be recorded.

Future versions may support:

- Placement
- Kills
- Team score
- Winning amount

Winnings must be credited through the wallet ledger.

Never modify wallet balance directly.

---

# 24. MATCH TEMPLATES

Create reusable match templates.

Template may define:

- Match type
- Entry fee
- Max players
- Default schedule
- Prize configuration
- Rules
- Room configuration

Admins can create a match from a template.

---

# 25. DAILY OPERATING WINDOW

Current intended operating window:

10:00 AM - 11:00 PM

This should be configurable in platform settings.

Do not hardcode these values throughout the code.

Use configuration/settings.

Timezone:

Asia/Dhaka

Store timestamps in UTC internally where practical.

Convert to Asia/Dhaka for display.

---

# 26. DEPOSIT SYSTEM

Users can deposit money.

Payment flow:

User
    ↓
Create payment
    ↓
Payment provider
    ↓
Checkout
    ↓
Payment completion
    ↓
Webhook
    ↓
Server-side verification
    ↓
Database transaction
    ↓
Wallet ledger
    ↓
Balance update

Never credit money merely because the frontend redirected to a success page.

---

# 27. ZINIPAY INTEGRATION

Existing payment provider:

ZiniPay

Known API concepts include:

/v1/payment/create

/v1/payment/verify

Authentication header:

zini-api-key

Existing invoice prefix:

RA_

Payment implementation must be isolated behind a payment service/provider interface.

Example:

PaymentProvider

    createPayment()
    verifyPayment()
    handleWebhook()

Do not spread ZiniPay-specific logic across the entire codebase.

This allows replacing the payment provider later.

---

# 28. PAYMENT RECORD

Create a payments table.

Possible fields:

- id
- user_id
- provider
- invoice_id
- transaction_id
- amount
- currency
- payment_method
- status
- provider_response
- metadata
- created_at
- updated_at
- verified_at

Payment statuses may include:

PENDING
PROCESSING
SUCCESS
FAILED
CANCELLED
EXPIRED
REFUNDED

---

# 29. WEBHOOK SECURITY

Payment webhooks must be treated as untrusted external input.

Verify:

- Signature/authentication if provider supports it
- Transaction ID
- Invoice ID
- Amount
- Currency
- Payment status

Prevent duplicate webhook processing.

Webhook processing must be idempotent.

If the same webhook arrives 10 times:

The wallet must be credited only once.

---

# 30. PAYMENT RECONCILIATION

Implement a way for administrators to inspect payment records.

Payment record must show:

- Internal payment ID
- Provider
- Invoice ID
- Transaction ID
- Amount
- Status
- Payment method
- User
- Timestamps

Admins should be able to identify discrepancies.

---

# 31. WITHDRAWAL SYSTEM

Current rules:

Minimum withdrawal:

৳50

Maximum withdrawal:

৳1000

Frequency:

Maximum 1 withdrawal per day

Eligibility:

User must have completed at least one eligible match.

Phone number:

Exactly 11 digits according to current Bangladesh requirement.

No bank account field is required in the current design.

The withdrawal system must remain configurable.

---

# 32. WITHDRAWAL STATES

Recommended:

PENDING
PROCESSING
APPROVED
REJECTED
COMPLETED
CANCELLED

Do not permanently delete withdrawal records.

---

# 33. WITHDRAWAL FLOW

User requests withdrawal.

Server checks:

1. Authenticated
2. Account active
3. Amount >= minimum
4. Amount <= maximum
5. Daily withdrawal limit
6. Eligible balance available
7. Completed-match requirement
8. Valid phone number
9. No conflicting pending withdrawal
10. User account not restricted

Then reserve the requested amount.

Do not allow the same funds to be withdrawn twice.

---

# 34. WITHDRAWAL ACCOUNTING

When a withdrawal is requested:

The system should reserve or debit funds according to the chosen accounting design.

The money must remain traceable.

If withdrawal is rejected:

Funds must be safely returned through a reversal/refund ledger entry.

Never simply overwrite the wallet balance.

---

# 35. QR CAMPAIGN SYSTEM

Support promotional QR campaigns.

A campaign can contain:

- campaign name
- code
- reward
- start date
- end date
- usage limit
- per-user usage limit
- active status

QR campaign claims must be recorded.

Prevent duplicate claims.

---

# 36. NOTIFICATION SYSTEM

Create a notification system.

Notification examples:

- Match joined
- Match starting
- Room released
- Match completed
- Deposit successful
- Withdrawal submitted
- Withdrawal completed
- Referral reward
- Promotion activated
- Admin announcement

Notifications should support:

- Read/unread
- Created time
- Type
- Optional action URL

---

# 37. REAL-TIME NOTIFICATIONS

Use Socket.IO where real-time behavior is useful.

Example:

Admin releases room.

Backend:

1. Updates database
2. Emits event
3. Connected participants receive event
4. UI updates automatically

Do not use WebSocket for everything.

Use normal REST requests for normal CRUD.

---

# 38. ADMIN DASHBOARD

Create a professional admin dashboard.

Dashboard should provide:

- Total users
- Active users
- Today's matches
- Upcoming matches
- Completed matches
- Total deposits
- Total withdrawals
- Pending withdrawals
- Payment issues
- Promotional usage
- Referral statistics

Do not expose unnecessary sensitive information.

---

# 39. USER MANAGEMENT

Admins with permission can:

- Search users
- View profile
- View match history
- View wallet transactions
- View deposits
- View withdrawals
- Suspend account
- Activate account
- Add internal notes where appropriate

Sensitive data should be protected.

---

# 40. AUDIT LOG

Create an audit log system.

Important admin actions should create records.

Examples:

- User suspended
- User activated
- Match created
- Match edited
- Room released
- Withdrawal approved
- Withdrawal rejected
- Manual wallet adjustment
- Promotion created
- Role changed

Audit log fields:

- actor_id
- action
- target_type
- target_id
- metadata
- IP where appropriate
- user_agent where appropriate
- timestamp

Audit logs should be append-only.

---

# 41. MANUAL WALLET ADJUSTMENT

Admins may need to correct legitimate financial issues.

If supported:

Never directly modify balance.

Instead create:

ADJUSTMENT

or

REVERSAL

ledger transaction.

Require:

- Reason
- Admin identity
- Amount
- Target user
- Audit log

For sensitive adjustments, consider requiring elevated permission.

---

# 42. SECURITY REQUIREMENTS

Security is a first-class requirement.

Implement:

- Helmet
- CORS configuration
- Rate limiting
- Input validation
- Parameterized database access through ORM
- Secure cookies where used
- CSRF protection where applicable
- Password hashing
- Refresh-token rotation
- Account lockout/rate limiting where appropriate
- Authorization middleware
- Audit logs
- Secure environment variables

Never commit secrets.

Never expose:

- Database credentials
- JWT secrets
- Payment API keys
- Internal service credentials

---

# 43. ENVIRONMENT VARIABLES

Use:

.env

.env.example

Never commit real secrets.

Example:

DATABASE_URL=

JWT_ACCESS_SECRET=

JWT_REFRESH_SECRET=

ZINIPAY_API_KEY=

ZINIPAY_BASE_URL=

REDIS_URL=

NEXT_PUBLIC_API_URL=

APP_URL=

NODE_ENV=

---

# 44. ERROR HANDLING

Backend must use centralized error handling.

Do not return random error formats.

Use a consistent response structure.

Example:

{
  "success": false,
  "error": {
    "code": "INSUFFICIENT_BALANCE",
    "message": "Insufficient eligible balance."
  }
}

Errors must not expose:

- Stack traces
- SQL queries
- Secrets
- Internal implementation details

in production.

---

# 45. API RESPONSE FORMAT

Use consistent responses.

Success:

{
  "success": true,
  "data": {}
}

Failure:

{
  "success": false,
  "error": {
    "code": "ERROR_CODE",
    "message": "Human readable message"
  }
}

Pagination:

{
  "success": true,
  "data": [],
  "pagination": {
    "page": 1,
    "limit": 20,
    "total": 100,
    "totalPages": 5
  }
}

---

# 46. API VERSIONING

Use:

/api/v1/

Example:

/api/v1/auth/login

/api/v1/matches

/api/v1/wallet

/api/v1/payments

This allows future API versions.

---

# 47. API MODULES

Expected API groups:

/api/v1/auth

/api/v1/users

/api/v1/matches

/api/v1/wallet

/api/v1/transactions

/api/v1/payments

/api/v1/withdrawals

/api/v1/referrals

/api/v1/promotions

/api/v1/notifications

/api/v1/admin

/api/v1/audit

---

# 48. PAGINATION

Never return unlimited database rows.

All list endpoints should support pagination.

Example:

?page=1&limit=20

Set reasonable maximum limits.

Example:

maximum limit = 100

---

# 49. SEARCH AND FILTERING

Admin lists should support:

- Search
- Status filter
- Date filter
- Type filter
- Pagination
- Sorting where appropriate

Do not construct unsafe raw SQL from user input.

---

# 50. FRONTEND DESIGN

Visual identity:

RESPawn Alley should feel like a premium gaming platform.

Primary design direction:

"Toxic Volt Neumorphic"

Primary colors:

Obsidian:
#101014

Secondary dark:
#17171d

Volt:
#a8ff1a

Use dark surfaces with volt green highlights.

Avoid generic blue/purple gaming gradients.

Do NOT use:

- Cyan-heavy UI
- Blue-purple neon
- Rainbow gradients
- Excessive glow
- Unnecessary glassmorphism
- Generic gaming template appearance

The design should feel:

- Premium
- Competitive
- Modern
- Fast
- Technical
- Clean

---

# 51. TYPOGRAPHY

Use:

Plus Jakarta Sans

and/or:

DM Sans

Typography hierarchy must be clear.

Avoid excessive font weights and decorative typography.

---

# 52. USER EXPERIENCE

The user should immediately understand:

- Current balance
- Promo balance
- Upcoming matches
- Available matches
- Match entry fee
- Match capacity
- Match status
- Room availability
- Recent transactions

Do not hide important financial information.

---

# 53. PLAYER DASHBOARD

Dashboard should include:

- Wallet balance
- Promo balance
- Quick deposit
- Upcoming matches
- Joined matches
- Recent transactions
- Notifications
- Referral information
- Promotional campaigns

The dashboard should be optimized for mobile.

---

# 54. MATCH CARD

Match cards should clearly show:

- Match name
- Solo/Duo/Squad
- Entry fee
- Players joined
- Maximum players
- Start time
- Status
- Join button

Example:

SOLO
৳20 ENTRY

32 / 48 PLAYERS

8:30 PM

[JOIN MATCH]

---

# 55. MATCH DETAILS

Match detail page should show:

- Match information
- Rules
- Entry fee
- Capacity
- Participants count
- Scheduled time
- Room information if released
- Join/cancel state
- User participation status

Room credentials must only be shown to eligible participants after release.

---

# 56. WALLET UI

Wallet page should contain:

Cash balance

Promo balance

Transaction history

Deposit button

Withdrawal button

Transaction filters

Transaction details

Use clear distinction between:

Withdrawable cash

and

Promotional credit

---

# 57. MOBILE RESPONSIVENESS

The web application must be mobile-first.

Target users may primarily use:

- Android phones
- Mobile browsers

The application must work properly at:

- 360px
- 390px
- 412px
- tablet
- desktop

Do not design only for desktop.

---

# 58. ACCESSIBILITY

Follow reasonable accessibility practices:

- Semantic HTML
- Keyboard navigation
- Proper labels
- Focus states
- Color contrast
- Screen-reader friendly controls

---

# 59. ANDROID APPLICATION

Create an Android/mobile client.

Preferred future approach:

React Native / Expo

unless native Android is specifically required.

The mobile client should communicate only with the API.

It must NOT connect directly to PostgreSQL.

The API is the single backend interface.

---

# 60. MOBILE FEATURES

Initial mobile application should support:

- Login
- Registration
- Dashboard
- Matches
- Match details
- Join match
- Wallet
- Deposit
- Withdrawal
- Transaction history
- Referral
- Notifications
- Profile

Admin functionality should not be included in the player mobile application.

---

# 61. DATABASE MIGRATIONS

Use Prisma migrations.

Never manually modify production database structure without a migration.

Every schema change should be reproducible.

---

# 62. SEED DATA

Create seed scripts for development.

Seed:

- Admin user
- Moderator user
- Test player users
- Roles
- Permissions
- Sample match templates
- Sample matches

Use clearly fake/test credentials.

Never use real payment information.

---

# 63. DEVELOPMENT ENVIRONMENT

Provide Docker Compose for local development.

Services:

- PostgreSQL
- Redis

Optional:

- pgAdmin

Application itself may run locally outside Docker during development.

---

# 64. LOGGING

Implement structured logging.

Use a logger such as:

Pino

Log:

- HTTP requests
- Errors
- Payment events
- Webhook events
- Important background jobs
- Authentication events

Never log:

- Passwords
- Access tokens
- Refresh tokens
- Payment secrets
- Full sensitive personal information

---

# 65. OBSERVABILITY

Prepare the application for:

- Error monitoring
- Performance monitoring
- Request tracing
- Health checks

Implement:

/health

and:

/ready

where appropriate.

---

# 66. BACKGROUND JOBS

Create jobs for:

- Match scheduling
- Automatic match status updates
- Expired payment handling
- Notification delivery
- Promotional expiration
- Cleanup tasks

Jobs must be idempotent.

---

# 67. TIME HANDLING

Database:

Prefer UTC.

Application display:

Asia/Dhaka

All date/time calculations must be explicit.

Never rely blindly on server local timezone.

---

# 68. FILE STORAGE

If users can upload:

- Profile pictures
- Verification documents
- Other assets

Do not store large files directly in PostgreSQL.

Use object/file storage.

Validate:

- MIME type
- Size
- Extension

Generate safe filenames.

---

# 69. RATE LIMITING

Rate-limit sensitive endpoints:

- Login
- Registration
- Password reset
- Payment creation
- Withdrawal creation
- Referral claims
- QR campaign claims
- Webhooks where appropriate

Do not rely only on frontend protection.

---

# 70. FRAUD / ABUSE PROTECTION

Design for abuse.

Potential abuse:

- Multiple accounts
- Referral farming
- Promo farming
- Duplicate payments
- Duplicate withdrawal requests
- Match slot race conditions
- Replay attacks
- Fake payment callbacks

Use:

- Database constraints
- Rate limits
- Idempotency keys
- Audit logs
- Server-side validation
- Transactional operations

---

# 71. IDEMPOTENCY

Critical operations should support idempotency.

Especially:

- Payment creation
- Payment webhook processing
- Wallet credit
- Withdrawal creation
- Promotional rewards
- Referral rewards

If the same request arrives twice, it must not create two financial operations.

---

# 72. TRANSACTION REFERENCE SYSTEM

Every financial operation should have a unique internal reference.

Example:

RA-DEP-XXXXXXXX

RA-WD-XXXXXXXX

RA-ENT-XXXXXXXX

RA-REF-XXXXXXXX

The exact format can be finalized during implementation.

---

# 73. SECURITY OF ROOM INFORMATION

Room ID/password should:

- Never appear in public APIs before release
- Never appear in HTML source before release
- Only be accessible to eligible participants
- Be logged carefully
- Be protected from unauthorized admin access where possible

---

# 74. ADMIN SECURITY

Admin routes must have:

- Authentication
- Role verification
- Permission verification
- Audit logging

Consider stronger authentication for Super Admin.

---

# 75. DATA PRIVACY

Do not expose unnecessary user data.

For example, public match participant lists should not reveal:

- Phone numbers
- Wallet information
- Sensitive profile data

Only expose information necessary for gameplay.

---

# 76. USER ACCOUNT STATES

Support:

ACTIVE
SUSPENDED
BANNED
DEACTIVATED

Business rules should determine what each state can do.

For example:

Suspended user:

- Cannot join matches
- Cannot withdraw
- Cannot claim promotions

depending on policy.

---

# 77. PLATFORM SETTINGS

Create a configurable platform settings system.

Settings may include:

- Minimum withdrawal
- Maximum withdrawal
- Daily withdrawal limit
- Match operating hours
- Referral reward
- New player promo
- Currency
- Maintenance mode

Do not hardcode business configuration throughout the application.

---

# 78. MAINTENANCE MODE

Admin should be able to activate maintenance mode.

During maintenance:

- Existing authenticated users may receive a maintenance message
- Critical admin access can remain available
- Payment/financial endpoints must be handled carefully

---

# 79. API SECURITY RULE

The frontend is NOT trusted.

For every operation:

Frontend request
    ↓
Authentication
    ↓
Authorization
    ↓
Validation
    ↓
Business rules
    ↓
Database transaction
    ↓
Response

Never:

Frontend
    ↓
Database

---

# 80. TESTING STRATEGY

Create tests in layers.

## Unit tests

Test:

- Wallet calculations
- Promo deduction
- Match state transitions
- Withdrawal eligibility
- Referral eligibility
- Validation

## Integration tests

Test:

- Auth
- Database
- Wallet transactions
- Match joining
- Payments
- Withdrawals

## End-to-end tests

Test complete user flows:

Register
→ Login
→ Deposit
→ Join match
→ Room released
→ Match completed
→ Winning credited
→ Withdrawal

---

# 81. CRITICAL TEST CASES

At minimum test:

### Wallet

User has ৳100 cash.

Entry fee ৳20.

Result:

৳80.

---

### Promo

Cash = ৳100

Promo = ৳5

Entry = ৳20

Result:

Cash = ৳85

Promo = ৳0

---

### Insufficient balance

Cash = ৳10

Promo = ৳5

Entry = ৳20

Join must fail.

No database changes.

---

### Concurrent match join

Two requests attempt to take the final slot.

Only one should succeed.

---

### Duplicate payment webhook

Same successful webhook arrives twice.

Only one wallet credit.

---

### Duplicate match join

Same user sends join request twice.

Only one participant record.

Only one financial deduction.

---

### Withdrawal race condition

Two simultaneous withdrawal requests.

System must prevent withdrawing the same balance twice.

---

# 82. DOCUMENTATION

Maintain:

docs/

    architecture.md
    database.md
    api.md
    authentication.md
    wallet.md
    payments.md
    matches.md
    withdrawals.md
    deployment.md
    security.md

Documentation must be updated as the system evolves.

---

# 83. GIT WORKFLOW

Use Git.

Branches:

main
develop
feature/*
fix/*
refactor/*

Commit messages should be meaningful.

Example:

feat(wallet): implement atomic entry fee deduction

fix(payment): prevent duplicate webhook credit

feat(matches): add room release workflow

---

# 84. CODE QUALITY

Code must be:

- Typed
- Modular
- Readable
- Testable
- Maintainable

Avoid:

- Any everywhere
- Huge functions
- Huge components
- Copy-pasted business logic
- Magic numbers
- Hardcoded secrets
- Unnecessary abstractions

Use clear naming.

---

# 85. TYPESCRIPT RULES

Enable strict mode.

tsconfig should use:

"strict": true

Avoid:

any

unless there is a documented reason.

Use shared types where appropriate.

---

# 86. DATABASE RULES

Important invariants must be enforced at the database level whenever practical.

Examples:

- Unique username
- Unique phone
- Unique match participation
- Unique payment transaction ID
- Unique referral relationship
- Valid foreign keys

Application validation is not a substitute for database constraints.

---

# 87. NO DIRECT BALANCE MUTATION

This is a strict rule.

Do NOT write business logic such as:

user.balance += amount

for financial operations.

Instead use a wallet service that:

1. Begins transaction
2. Locks relevant wallet row
3. Checks current balance
4. Creates ledger entry
5. Updates balance snapshot if used
6. Commits transaction

---

# 88. BALANCE SNAPSHOT

A cached balance field may exist for fast reads.

However:

Ledger = source of financial truth.

Balance snapshot = optimized current state.

Implement reconciliation tools later to detect inconsistencies.

---

# 89. PAYMENT SUCCESS RULE

A payment is considered successful only after:

- Provider confirmation
- Server-side verification
- Correct amount
- Correct invoice
- Correct user
- Valid transaction
- No duplicate processing

Then:

Create wallet credit ledger entry.

---

# 90. ADMIN UI DESIGN

Admin dashboard should use a separate visual hierarchy from the player interface.

Player interface:

Gaming-focused.

Admin interface:

Operational-focused.

Admin should prioritize:

- Tables
- Filters
- Status badges
- Search
- Analytics
- Actions
- Audit information

Avoid making the admin dashboard look like a gaming landing page.

---

# 91. ERROR UX

User-facing errors should be understandable.

Bad:

"Foreign key constraint failed."

Good:

"Unable to join this match right now. Please try again."

Developer logs should retain technical details.

---

# 92. LOADING STATES

Every async UI operation must have proper loading states.

Avoid buttons that appear clickable while an operation is running.

Example:

[JOIN MATCH]

becomes:

[JOINING...]

and cannot be clicked repeatedly.

---

# 93. DOUBLE-SUBMISSION PROTECTION

Frontend:

Disable button while request is pending.

Backend:

Use idempotency and database constraints.

Both are required.

---

# 94. EMPTY STATES

Every major list must have a meaningful empty state.

Examples:

No upcoming matches.

No transactions yet.

No notifications.

No referrals yet.

---

# 95. MOBILE FIRST

Prioritize mobile experience.

Most players will likely use mobile devices.

Important actions should be easily reachable.

---

# 96. PERFORMANCE

Optimize:

- Database indexes
- API queries
- Pagination
- Frontend bundles
- Images
- Caching
- Real-time connections

Avoid unnecessary database queries.

Use proper relation loading.

Avoid N+1 queries.

---

# 97. CACHING

Redis can be used for:

- Rate limits
- Sessions where appropriate
- Temporary state
- Caching
- Job queues
- Real-time scaling

Do not cache financial state in a way that can become authoritative.

---

# 98. SCALABILITY

Initial platform should comfortably support:

- Thousands of registered users
- Thousands of daily visitors
- Hundreds of concurrent active users

Architecture should allow future horizontal scaling.

---

# 99. DEPLOYMENT

Production components:

Frontend:
Next.js

Backend:
Node.js

Database:
PostgreSQL

Cache/Queue:
Redis

Reverse proxy:
Nginx or managed platform equivalent

SSL:
HTTPS

All production traffic must use HTTPS.

---

# 100. DEPLOYMENT ENVIRONMENTS

Maintain:

Development
Staging
Production

Never develop directly against production.

---

# 101. BACKUPS

PostgreSQL must have automated backups.

Document:

- Backup frequency
- Retention
- Restore process

A backup that has never been tested is just an inspirational story.

---

# 102. DATABASE RESTORE

Document how to:

- Restore backup
- Verify integrity
- Bring application back online

---

# 103. PAYMENT FAILURE RECOVERY

Create admin visibility for:

- Pending payments
- Failed payments
- Successful provider payments without wallet credit
- Duplicate callbacks
- Reconciliation issues

Financial failures must be recoverable.

---

# 104. MATCH FAILURE RECOVERY

If a match is cancelled:

Define what happens to entry fees.

Expected behavior should generally be:

Entry fee returned through a refund/reversal ledger transaction.

Do not simply delete the match.

---

# 105. MATCH CANCELLATION

Cancellation should:

- Change match status
- Prevent new joins
- Process eligible refunds
- Notify participants
- Create audit log

Refund operations must be idempotent.

---

# 106. NOTIFICATION PREFERENCES

Future-ready design should support preferences such as:

- Match notifications
- Payment notifications
- Promotional notifications
- Referral notifications
- System notifications

---

# 107. INTERNATIONALIZATION

Initial language:

English for admin/developer interfaces.

Player-facing interface may later support:

Bangla

Do not hardcode text in a way that makes localization impossible.

---

# 108. CURRENCY

Initial currency:

BDT / ৳

Do not assume floating point arithmetic for money.

Use integer minor units where appropriate.

For BDT:

৳20.50 can be represented as 2050 poisha.

If the platform currently only supports whole BDT, still design financial calculations safely.

---

# 109. MONEY CALCULATION

Never use JavaScript floating point for authoritative financial calculations.

Prefer integer minor units or Decimal types.

PostgreSQL numeric/decimal may be used where appropriate.

---

# 110. USER FLOW

New user:

Register
    ↓
Profile setup
    ↓
Receive pending new-player promotion
    ↓
Browse matches
    ↓
Deposit
    ↓
Join paid match
    ↓
Promotion activates according to rules
    ↓
Play
    ↓
Match completed
    ↓
Winning/refund if applicable
    ↓
Withdraw eligible cash

---

# 111. ADMIN FLOW

Admin:

Login
    ↓
Dashboard
    ↓
Create match/template
    ↓
Open registration
    ↓
Monitor participants
    ↓
Release room
    ↓
Match becomes live
    ↓
Complete match
    ↓
Record results
    ↓
Process winnings
    ↓
Review withdrawals
    ↓
Monitor payments
    ↓
Review audit logs

---

# 112. DEVELOPMENT PHASES

DO NOT attempt to build the entire system in one giant implementation.

Build incrementally.

## PHASE 0

Project setup.

Deliver:

- Monorepo
- TypeScript
- Next.js
- Express
- PostgreSQL
- Prisma
- Redis
- Docker
- ESLint
- Prettier
- Environment configuration
- Git configuration

---

## PHASE 1

Database foundation.

Deliver:

- Prisma schema
- Migrations
- Users
- Roles
- Permissions
- Audit log
- Wallet structure

Do not implement the entire UI yet.

---

## PHASE 2

Authentication.

Deliver:

- Registration
- Login
- Logout
- Refresh token
- Password hashing
- Authentication middleware
- Role middleware
- Profile

---

## PHASE 3

Wallet.

Deliver:

- Cash wallet
- Promo wallet
- Ledger
- Atomic transactions
- Transaction history
- Balance APIs

Write tests before continuing.

---

## PHASE 4

Matches.

Deliver:

- Match CRUD
- Match templates
- Match state machine
- Participants
- Capacity control
- Atomic entry
- Promo-first deduction

---

## PHASE 5

Room release.

Deliver:

- Admin room release
- Participant-only room visibility
- Socket.IO event
- Notifications

---

## PHASE 6

Payments.

Deliver:

- Payment abstraction
- ZiniPay provider
- Create payment
- Verify payment
- Webhook
- Idempotency
- Wallet credit
- Payment admin view

This phase requires extensive testing.

---

## PHASE 7

Withdrawals.

Deliver:

- Withdrawal request
- Eligibility
- Limits
- Daily restriction
- Admin approval/rejection
- Refund/reversal handling
- Audit logs

---

## PHASE 8

Referral + promotions.

Deliver:

- Referral codes
- Referral relationship
- ৳10 reward
- ৳5 new-player promotion
- QR campaigns
- Promotion lifecycle

---

## PHASE 9

Notifications.

Deliver:

- Notification database
- In-app notifications
- Socket.IO
- Match events
- Payment events
- Withdrawal events
- Referral events

---

## PHASE 10

Player frontend.

Deliver:

- Landing page
- Authentication
- Dashboard
- Matches
- Match details
- Wallet
- Transactions
- Withdrawals
- Referrals
- Promotions
- Notifications
- Profile

---

## PHASE 11

Admin frontend.

Deliver:

- Dashboard
- User management
- Match management
- Templates
- Payments
- Withdrawals
- Promotions
- Referrals
- Audit logs
- Settings
- Roles/permissions

---

## PHASE 12

Android.

Deliver:

- Authentication
- Dashboard
- Matches
- Match details
- Wallet
- Deposit
- Withdrawal
- Notifications
- Profile

---

## PHASE 13

Testing and hardening.

Deliver:

- Unit tests
- Integration tests
- E2E tests
- Security review
- Concurrency testing
- Payment idempotency testing
- Load testing
- Error handling review

---

## PHASE 14

Production deployment.

Deliver:

- Production environment
- PostgreSQL
- Redis
- HTTPS
- Domain
- CI/CD
- Backups
- Monitoring
- Logging
- Health checks

---

# 113. AI DEVELOPMENT INSTRUCTIONS

You are the primary AI development assistant for this project.

Follow these rules.

## Rule 1

Do not attempt to generate the entire project in one response.

Build incrementally.

## Rule 2

Before implementing a major module:

Explain:

- Architecture
- Files to create/change
- Database changes
- API endpoints
- Important business rules
- Security considerations

Then implement.

## Rule 3

Never silently change established business rules.

If a requirement is ambiguous:

Identify the ambiguity.

Choose a safe default only when reasonable.

Document the assumption.

## Rule 4

Never invent payment-provider behavior.

If ZiniPay documentation is unavailable in the current context:

Create a provider abstraction and clearly mark the provider-specific implementation that requires official documentation.

Do not invent webhook signatures or undocumented fields.

## Rule 5

Do not expose secrets.

Use environment variables.

## Rule 6

Never trust frontend calculations for financial operations.

## Rule 7

Never directly modify wallet balances outside the wallet service.

## Rule 8

Every financial operation must be atomic and idempotent.

## Rule 9

Every admin-sensitive action must be authorized.

## Rule 10

Every major feature must include tests.

---

# 114. AI CODING STYLE

When generating code:

- Use TypeScript
- Prefer explicit types
- Keep functions small
- Keep modules focused
- Use async/await
- Handle errors
- Validate external input
- Avoid unnecessary abstraction
- Avoid overengineering
- Add comments only when they explain non-obvious logic

Do not generate placeholder code that pretends to work.

If something is intentionally incomplete:

Mark it clearly with:

TODO

and explain what remains.

---

# 115. AI RESPONSE FORMAT

For each implementation phase, respond in this structure:

## 1. Goal

What is being implemented.

## 2. Architecture

How it works.

## 3. Files

Files created/modified.

## 4. Database

Schema/migration changes.

## 5. API

Endpoints.

## 6. Implementation

Actual code.

## 7. Tests

Tests added.

## 8. Verification

Commands to run.

## 9. Remaining Work

What is intentionally not implemented yet.

Do not skip verification.

---

# 116. COMMANDS

The project should eventually support commands such as:

pnpm install

pnpm dev

pnpm build

pnpm test

pnpm lint

pnpm typecheck

pnpm prisma migrate dev

pnpm prisma generate

pnpm prisma db seed

Use package scripts consistently.

---

# 117. DEFINITION OF DONE

A feature is NOT complete merely because code exists.

A feature is complete when:

- Code compiles
- TypeScript passes
- Validation exists
- Authorization exists
- Database constraints exist where necessary
- Error handling exists
- Tests exist
- UI works where applicable
- Loading states exist
- Empty states exist
- Security implications have been considered
- Documentation is updated

---

# 118. CURRENT PROJECT PRIORITY

The immediate priority is:

Build a stable production-grade backend and database foundation first.

Priority order:

1. Architecture
2. Database
3. Authentication
4. Wallet
5. Matches
6. Payments
7. Withdrawals
8. Referrals/promotions
9. Notifications
10. Player UI
11. Admin UI
12. Mobile
13. Testing/hardening
14. Deployment

Do not start by building decorative landing-page animations.

Functionality first.

---

# 119. VISUAL PRIORITY

Once the core architecture is stable, the player UI should follow:

RESPawn Alley

"Toxic Volt Neumorphic"

Colors:

#101014
#17171d
#a8ff1a

Typography:

Plus Jakarta Sans
DM Sans

Design characteristics:

- Premium
- Dark
- Minimal
- Gaming
- Technical
- Neumorphic
- High usability
- Strong mobile experience

Avoid:

- Generic SaaS appearance
- Generic esports templates
- Blue/purple neon
- Excessive gradients
- Excessive animations

---

# 120. FINAL ARCHITECTURAL PRINCIPLE

The platform should be designed so that:

Frontend can change.

Mobile app can change.

Payment provider can change.

Hosting provider can change.

But:

Business logic
Database integrity
Wallet ledger
Authentication
Authorization

remain stable.

The backend API is the central contract.

The PostgreSQL database is the source of truth.

The wallet ledger is the source of financial truth.

The client is never trusted.

---

# 121. FIRST TASK

START WITH PHASE 0.

Do NOT start building the complete application.

First:

1. Analyze this specification.
2. Identify contradictions or missing decisions.
3. Propose the final monorepo architecture.
4. Propose the initial PostgreSQL/Prisma schema.
5. Propose the dependency list.
6. Propose Docker Compose.
7. Propose environment variables.
8. Propose development scripts.
9. Explain how the architecture will support future Android/mobile clients.
10. Then implement Phase 0.

After Phase 0 is verified, proceed to Phase 1.

Do not jump ahead without completing and verifying each phase.

---

# END OF SPECIFICATION