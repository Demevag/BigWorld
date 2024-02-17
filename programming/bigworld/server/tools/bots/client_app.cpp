#include "script/first_include.hpp"

#include "client_app.hpp"

#include "bots_config.hpp"
#include "bot_entity.hpp"
#include "script_bot_entity.hpp"

#include "entity_type.hpp"
#include "main_app.hpp"
#include "movement_controller.hpp"
#include "py_entities.hpp"

#include "pyscript/personality.hpp"

#include "cstdmf/bgtask_manager.hpp"

#include "connection_model/bw_entity.hpp"

#include "network/space_data_mapping.hpp"

DECLARE_DEBUG_COMPONENT2("Bots", 0)

BW_BEGIN_NAMESPACE

// -----------------------------------------------------------------------------
// Section: ClientApp
// -----------------------------------------------------------------------------

PY_TYPEOBJECT_WITH_WEAKREF(ClientApp)

PY_BEGIN_METHODS(ClientApp)
/*~ function ClientApp logOn
 *  @components{ bots }
 *  This function initiates the log on process for the simulated client
 *  to connect to a BigWorld server.
 */
PY_METHOD(logOn)
/*~ function ClientApp logOff
 *  @components{ bots }
 *  This function gracefully disconnects the simulated client from the
 *  BigWorld server it is connected with. If the client is offline, this
 *  function has no effect.
 */
PY_METHOD(logOff)
/*~ function ClientApp dropConnection
 *  @components{ bots }
 *  This function immediately drops the connection between the simulated
 *  client and the BigWorld server. Use this function to simulate a sudden
 *  network disconnection. If the client is offline, this function has no
 *  effect.
 */
PY_METHOD(dropConnection)
/*~ function ClientApp setConnectionLossRatio
 *  @components{ bots }
 *  This function sets packet lost ratio for the connection between the
 *  simulated client and the BigWorld server. The input ratio must be in the
 *  range of [0.0,1.0]. 0.0 means no packet loss, whereas 1.0 mean 100
 *  percent packet loss. Use this function to simulate an unstable network
 *  connection with certain packet loss. If the client is offline, this
 *  function has no effect.
 *
 *  @param   lossRatio       (float)     Packet loss ratio.
 */

PY_METHOD(setConnectionLossRatio)
/*~ function ClientApp setConnectionLatency
 *  @components{ bots }
 *  This function sets packet latency for the connection between the
 *  simulated client and the BigWorld server. The input values sets the
 *  latency range in milliseconds. Use this function to simulate an unstable
 *  network connection with variable data latency. If the client is offline,
 *  this function has no effect.
 *
 *  @param   minLatency      (float)     Minimum latency between packets.
 *  @param   maxLatency      (float)     Maximum latency between packets.
 */
PY_METHOD(setConnectionLatency)
/*~ function ClientApp setMovementController
 *  @components{ bots }
 *  This function sets the movement controller for the simulated client.
 *  The client use the patrol path generated by the movement controller to
 *  navigated around game world in order to simulate actual player movement.
 *  Upon failure, the previous movement controller will be reinstated.
 *
 *  BW provides only few elementary movement controllers with simple patrol
 *  paths. We recommend you use default movement controller. It reads in
 *  custom designed patrol paths which you should create specifically for
 *  your game world environment. For details of how to custom desige patrol
 *  path, check the server operation guide section 8.4.
 *
 *  @param   movementController  (string)Name of the movement controller.
 *                                       Note: The movement controller must
 *                                       have been compiled and visible to
 *                                       the Bots app.
 *
 *  @return              (boolean)   True if successful, otherwise, False.
 */
PY_METHOD(setMovementController)
/*~ function ClientApp moveTo
 *  @components{ bots }
 *  This function sets a destination point for the player entity controlled
 *  by the simulated client.
 *
 *  @param   destination     (Vector3)   Destination for the player entity
 *                                       to move to.
 */
PY_METHOD(moveTo)
/*~ function ClientApp faceTowards
 *  @components{ bots }
 *  This function sets a direction that the player entity controlled
 *  by the simulated client should face
 *
 *  @param   direction       (Vector3)   Direction for the player entity
 *                                       to face.
 */
PY_METHOD(faceTowards)
/*~ function ClientApp snapTo
 *  @components{ bots }
 *  This function sets(immediately) the position of the player entity
 *  controlled by the simulated client.
 *
 *  @param   position        (Vector3)   New position for the player entity.
 */
PY_METHOD(snapTo)
/*~ function ClientApp stop
 *  @components{ bots }
 *  This function stops the movement of the player entity controlled
 *  by the simulated client.
 *
 */
PY_METHOD(stop)
/*~ function ClientApp addTimer
 *  @components{ bots }
 *  This function adds a timer to the simulated client. The callback function
 *  included in the input parameters will be invoked during the next tick
 *  after specified number of seconds has lapsed.
 *
 *  @param   interval    (float)     time interval for triggering the timer.
 *  @param   callback    (PyObject)  Callback function.
 *  @param   repeat      (boolean)   Should the timer be triggered repeatly.
 *
 *  @return  id      (integer)       The ID for the newly added timer.
 */
PY_METHOD(addTimer)
/*~ function ClientApp delTimer
 *  @components{ bots }
 *  This function deletes an existing timer on the simulated client.
 *
 *  @param   id      (integer)   Timer ID.
 */
PY_METHOD(delTimer)
/*~ function ClientApp clientTime
 *  @components{ bots }
 *  This function returns the time in seconds since the client has connected
 *  to the server.
 *
 *  @return  time    (float)     The time in seconds since client connected.
 */
PY_METHOD(clientTime)
/*~ function ClientApp serverTime
 *  @components{ bots }
 *  This function returns the server time. This is the time that all entities
 *  are at, as far as the server itself is concerned.
 *
 *  @return  time    (float)     The current time on the server.
 */
PY_METHOD(serverTime)
PY_END_METHODS()

PY_BEGIN_ATTRIBUTES(ClientApp)
/*~ attribute ClientApp id
 *  @components{ bots }
 *  The player entity id of the simulated client
 *  @type Read-only integer
 */
PY_ATTRIBUTE(id)
/*~ attribute ClientApp spaceID
 *  @components{ bots }
 *  The ID of the space that the player entity is currently in.
 *  @type Read-only integer
 */
PY_ATTRIBUTE(spaceID)
/*~ attribute ClientApp player
 *  @components{ bots }
 *  The player entity of the simulated client
 *  @type Read-only ScriptObject
 */
PY_ATTRIBUTE(player)
/*~ attribute ClientApp loginName
 *  @components{ bots }
 *  The login name used by the simulated client.
 *  @type Read-only string
 */
PY_ATTRIBUTE(loginName)
/*~ attribute ClientApp loginPassword
 *  @components{ bots }
 *  The password used by the simulated client.
 *  @type Read-only string
 */
PY_ATTRIBUTE(loginPassword)
/*~ attribute ClientApp tag
 *  @components{ bots }
 *  The tag name associated with the simulated client.
 *  @type string
 */
PY_ATTRIBUTE(tag)
/*~ attribute ClientApp speed
 *  @components{ bots }
 *  The speed of the player entity controlled by the simulated client.
 *  @type float
 */
PY_ATTRIBUTE(speed)
/*~ attribute ClientApp position
 *  @components{ bots }
 *  The position of the player entity of the simulated client.
 *  @type Vector3
 */
PY_ATTRIBUTE(position)
/*~ attribute ClientApp yaw
 *  @components{ bots }
 *  The yaw (direction) of the player entity of the simulated client.
 *  @type Vector3
 */
PY_ATTRIBUTE(yaw)
/*~ attribute ClientApp pitch
 *  @components{ bots }
 *  The pitch (direction) of the player entity of the simulated client.
 *  @type Vector3
 */
PY_ATTRIBUTE(pitch)
/*~ attribute ClientApp roll
 *  @components{ bots }
 *  The roll (direction) of the player entity of the simulated client.
 *  @type Vector3
 */
PY_ATTRIBUTE(roll)
/*~ attribute ClientApp entities
 *  @components{ bots }
 *  entities contains a list of all the entities which currently within
 *  the player entity's AOI.
 *
 *  @type Read-only PyEntities
 */
PY_ATTRIBUTE(entities)
/*~ attribute ClientApp autoMove
 *  @components{ bots }
 *  The flag indicates whether the player entity is moving automatically.
 *  (either under movement controller or random movement.
 *  @type boolean
 */
PY_ATTRIBUTE(autoMove)
/*~ attribute ClientApp isOnline
 *  @components{ bots }
 *  Indicates whether the simulated client is connected to a BigWorld server.
 *  @type Read-only boolean
 */
PY_ATTRIBUTE(isOnline)
/*~ attribute ClientApp isMoving
 *  @components{ bots }
 *  Indicates whether the player entity under controlled of the simulated
 *  client is moving.
 *  @type Read-only boolean
 */
PY_ATTRIBUTE(isMoving)
/*~ attribute ClientApp isDestroyed
 *  @components{ bots }
 *  Indicates whether player entity of the simulated client has been
 *  destroyed.
 *  @type Read-only boolean
 */
PY_ATTRIBUTE(isDestroyed)
PY_END_ATTRIBUTES()

/*~ callback Entity.onTick
 *  @components{ bots }
 *  If present, this method is called every game tick on the entity
 *  while the client is in a space on a BigWorld server. This facilitates
 *  custom game logic implementation.
 */

// -----------------------------------------------------------------------------
// Section: LogOnStatus enumeration
// -----------------------------------------------------------------------------

class LogOnStatusEnum : public LogOnStatus
{
  public:
    PY_BEGIN_ENUM_MAP_NOPREFIX(Status)
    PY_ENUM_VALUE(NOT_SET)
    PY_ENUM_VALUE(LOGGED_ON)
    PY_ENUM_VALUE(LOGGED_ON_OFFLINE)
    PY_ENUM_VALUE(CONNECTION_FAILED)
    PY_ENUM_VALUE(DNS_LOOKUP_FAILED)
    PY_ENUM_VALUE(UNKNOWN_ERROR)
    PY_ENUM_VALUE(CANCELLED)
    PY_ENUM_VALUE(ALREADY_ONLINE_LOCALLY)
    PY_ENUM_VALUE(PUBLIC_KEY_LOOKUP_FAILED)
    PY_ENUM_VALUE(LAST_CLIENT_SIDE_VALUE)
    PY_ENUM_VALUE(LOGIN_MALFORMED_REQUEST)
    PY_ENUM_VALUE(LOGIN_BAD_PROTOCOL_VERSION)
    PY_ENUM_VALUE(LOGIN_REJECTED_NO_SUCH_USER)
    PY_ENUM_VALUE(LOGIN_REJECTED_INVALID_PASSWORD)
    PY_ENUM_VALUE(LOGIN_REJECTED_ALREADY_LOGGED_IN)
    PY_ENUM_VALUE(LOGIN_REJECTED_BAD_DIGEST)
    PY_ENUM_VALUE(LOGIN_REJECTED_DB_GENERAL_FAILURE)
    PY_ENUM_VALUE(LOGIN_REJECTED_DB_NOT_READY)
    PY_ENUM_VALUE(LOGIN_REJECTED_ILLEGAL_CHARACTERS)
    PY_ENUM_VALUE(LOGIN_REJECTED_SERVER_NOT_READY)
    PY_ENUM_VALUE(LOGIN_REJECTED_UPDATER_NOT_READY) // No longer used
    PY_ENUM_VALUE(LOGIN_REJECTED_NO_BASEAPPS)
    PY_ENUM_VALUE(LOGIN_REJECTED_BASEAPP_OVERLOAD)
    PY_ENUM_VALUE(LOGIN_REJECTED_CELLAPP_OVERLOAD)
    PY_ENUM_VALUE(LOGIN_REJECTED_BASEAPP_TIMEOUT)
    PY_ENUM_VALUE(LOGIN_REJECTED_BASEAPPMGR_TIMEOUT)
    PY_ENUM_VALUE(LOGIN_REJECTED_DBAPP_OVERLOAD)
    PY_ENUM_VALUE(LOGIN_REJECTED_LOGINS_NOT_ALLOWED)
    PY_ENUM_VALUE(LOGIN_REJECTED_RATE_LIMITED)
    PY_ENUM_VALUE(LOGIN_REJECTED_BAN)

    PY_ENUM_VALUE(LOGIN_REJECTED_AUTH_SERVICE_NO_SUCH_ACCOUNT)
    PY_ENUM_VALUE(LOGIN_REJECTED_AUTH_SERVICE_LOGIN_DISALLOWED)
    PY_ENUM_VALUE(LOGIN_REJECTED_AUTH_SERVICE_UNREACHABLE)
    PY_ENUM_VALUE(LOGIN_REJECTED_AUTH_SERVICE_INVALID_RESPONSE)
    PY_ENUM_VALUE(LOGIN_REJECTED_AUTH_SERVICE_GENERAL_FAILURE)

    PY_ENUM_VALUE(LOGIN_REJECTED_NO_LOGINAPP)
    PY_ENUM_VALUE(LOGIN_REJECTED_NO_LOGINAPP_RESPONSE)
    PY_ENUM_VALUE(LOGIN_REJECTED_NO_BASEAPP_RESPONSE)

    PY_ENUM_VALUE(LOGIN_REJECTED_REGISTRATION_NOT_CONFIRMED)
    PY_ENUM_VALUE(LOGIN_REJECTED_NOT_REGISTERED)
    PY_ENUM_VALUE(LOGIN_REJECTED_ACTIVATING)
    PY_ENUM_VALUE(LOGIN_REJECTED_UNABLE_TO_PARSE_JSON)
    PY_ENUM_VALUE(LOGIN_REJECTED_USERS_LIMIT)
    PY_ENUM_VALUE(LOGIN_REJECTED_LOGIN_QUEUE)

    PY_ENUM_VALUE(LOGIN_CUSTOM_DEFINED_ERROR)
    PY_ENUM_VALUE(LAST_SERVER_SIDE_VALUE)
    PY_END_ENUM_MAP()
};

PY_ENUM_CONVERTERS_DECLARE(LogOnStatusEnum::Status)

PY_ENUM_MAP(LogOnStatusEnum::Status)
PY_ENUM_CONVERTERS_SCATTERED(LogOnStatusEnum::Status)

// -----------------------------------------------------------------------------
// Section: Construction/Destruction
// -----------------------------------------------------------------------------

/**
 *  Constructor.
 *
 *  @param name         The user account name to login under.
 *  @param password     The password to use.
 *  @param transport    The transport to use.
 *  @param tag          The tag for this bot.
 *  @param pType        The Python type object.
 */
ClientApp::ClientApp(const BW::string&   name,
                     const BW::string&   password,
                     ConnectionTransport transport,
                     const BW::string&   tag,
                     PyTypeObject*       pType)
  : PyObjectPlusWithWeakReference(pType)
  , ServerConnectionHandler()
  , BWEntityFactory()
  , BWSpaceDataListener()
  , BWStreamDataHandler()
  , spaceDataStorage_(new SpaceDataMappings())
  , pConnection_(
      new BWServerConnection(*this,
                             spaceDataStorage_,
                             MainApp::instance().loginChallengeFactories(),
                             MainApp::instance().condemnedInterfaces(),
                             EntityType::entityDefConstants(),
                             0.0))
  , isDestroyed_(false)
  , isDormant_(true)
  , logOnRetryTime_(0)
  , userName_(name)
  , userPasswd_(password)
  , transport_(transport)
  , tag_(tag)
  , speed_(6.f + float(rand()) * 2.f / float(RAND_MAX))
  , pMovementController_(NULL)
  , autoMove_(true)
  , pDest_(NULL)
  , entities_()
{
    pConnection_->setHandler(this);
    pConnection_->addSpaceDataListener(*this);
    pConnection_->setStreamDataFallbackHandler(*this);

    if (BotsConfig::shouldUseScripts()) {
        entities_ = ScriptObject(new PyEntities(pConnection_->entities()),
                                 ScriptObject::FROM_NEW_REFERENCE);
    }

    // Going behind BWConnection's back here.
    pConnection_->pServerConnection()->pLogOnParamsEncoder(
      MainApp::instance().pLogOnParamsEncoder());

    pConnection_->pTaskManager(BgTaskManager::pInstance());

    this->logOn();
}

/**
 *  Destructor.
 */
ClientApp::~ClientApp()
{
    if (!isDestroyed_) {
        this->destroy();
    }

    pConnection_->removeSpaceDataListener(*this);
    pConnection_->clearStreamDataFallbackHandler();
}

// -----------------------------------------------------------------------------
// Section: Lifecycle interface
// -----------------------------------------------------------------------------

/**
 *  This method is called every tick (probably 100 milliseconds).
 */
bool ClientApp::tick(float dTime)
{
    PyObjectPtr pSelf(this);
    // if it is dormant skip call tick.
    if (isDormant_) {
        return true;
    }

    bool wasOnline = pConnection_->isOnline() || pConnection_->isLoggingIn();

    pConnection_->update(dTime);

    if (wasOnline && !pConnection_->isOnline() &&
        !pConnection_->isLoggingIn()) {
        // Either just became dormant, or just disconnected
        // and want to be desroyed.
        return isDormant_;
    }

    Entity* pPlayer = this->pPlayerEntity();

    if (dTime > 0.f && pPlayer != NULL && pPlayer->isInWorld()) {
        if (BotsConfig::shouldUseScripts()) {
            MF_ASSERT(pPlayer->pPyEntity());

            ScriptObject pyPlayer = pPlayer->pPyEntity();
            ScriptArgs   args = ScriptArgs::create(pConnection_->serverTime());

            pyPlayer.callMethod("onTick",
                                args,
                                ScriptErrorPrint(),
                                /* allowNullMethod */ true);

            // Handle any user timeouts
            this->processTimers();
        }

        if (this->isPlayerMovable()) {
            // Movement ordered by moveTo() takes precedence over
            // movement by movement controller
            if (pDest_.get() != NULL) {
                const float closeEnough  = 1.0;
                Vector3     displacement = *pDest_ - this->position();
                float       length       = displacement.length();

                if (length < closeEnough) {
                    pDest_.reset(NULL);
                } else {
                    displacement *= speed_ * dTime / length;
                    Direction3D direction = this->direction();
                    direction.yaw         = displacement.yaw();
                    this->updatePosition(this->position() + displacement,
                                         direction);
                }
            } else if (autoMove_) {
                this->addMove(dTime);
            }
        } else {
            // since we don't have control of the player
            // remove any destination
            pDest_.reset(NULL);
        }
    }

    pConnection_->updateServer();

    return true;
}

/**
 *  This method destroys this ClientApp.
 */
void ClientApp::destroy()
{
    if (isDestroyed_) {
        return;
    }

    isDestroyed_ = true;

    ScriptObject module = MainApp::instance().getPersonalityModule();

    pMovementController_.reset(NULL);

    if (module && (this->id() != NULL_ENTITY_ID)) {
        module.callMethod("onClientAppDestroy",
                          ScriptArgs::create(this->id()),
                          ScriptErrorPrint("onClientAppDestroy"),
                          /* allowNullMethod */ true);
    }

    this->logOff();

    pConnection_->clearAllEntities();

    MF_ASSERT(this->id() == NULL_ENTITY_ID);

    entities_ = ScriptObject();
}

// -----------------------------------------------------------------------------
// Section: Connection interface
// -----------------------------------------------------------------------------

/**
 *  This method logs on the client.
 */
void ClientApp::logOn()
{
    logOnRetryTime_ = 0;

    if (isDestroyed_) {
        return;
    }

    isDormant_ = false;

    if (pConnection_->isLoggingIn() || pConnection_->isOnline()) {
        return;
    }

    pConnection_->logOnTo(BotsConfig::serverName().c_str(),
                          userName_.c_str(),
                          userPasswd_.c_str(),
                          transport_);
}

void ClientApp::logOff()
{
    if (pConnection_->isOnline()) {
        pConnection_->logOff();
    }
}

void ClientApp::dropConnection()
{
    if (pConnection_->isOnline()) {
        // Bypassing BWConnection here.
        pConnection_->pServerConnection()->disconnect(
          /* informServer */ false);
    }
}

void ClientApp::setConnectionLossRatio(float lossRatio)
{
    if (lossRatio < 0.f || lossRatio > 1.f) {
        PyErr_Format(PyExc_ValueError,
                     "Loss ratio for connection "
                     "should be within [0.0 - 1.0]");
        return;
    }
    // TODO: Don't bypass BWConnection
    pConnection_->pServerConnection()->networkInterface().setLossRatio(
      lossRatio);
}

void ClientApp::setConnectionLatency(float latencyMin, float latencyMax)
{
    // TODO: add more checking and make it more sophisticated.
    if (latencyMin >= latencyMax) {
        PyErr_Format(PyExc_ValueError,
                     "latency max should be larger than latency min");
        return;
    }
    // TODO: Don't bypass BWConnection
    pConnection_->pServerConnection()->networkInterface().setLatency(
      latencyMin, latencyMax);
}

/**
 *  This method sets the sendTimeReportThreshold of our server
 *  connection.
 */
void ClientApp::connectionSendTimeReportThreshold(double threshold)
{
    pConnection_->pServerConnection()->sendTimeReportThreshold(threshold);
}

// -----------------------------------------------------------------------------
// Section: Accessors
// -----------------------------------------------------------------------------

EntityID ClientApp::id() const
{
    BWEntity* pPlayer = pConnection_->pPlayer();

    if (pPlayer == NULL || pPlayer->isDestroyed()) {
        return NULL_ENTITY_ID;
    }

    return pPlayer->entityID();
}

SpaceID ClientApp::spaceID() const
{
    BWEntity* pPlayer = pConnection_->pPlayer();

    if (pPlayer == NULL || pPlayer->isDestroyed()) {
        return NULL_SPACE_ID;
    }

    return pPlayer->spaceID();
}

Entity* ClientApp::pPlayerEntity() const
{
    return static_cast<Entity*>(pConnection_->pPlayer());
}

ScriptObject ClientApp::player() const
{
    Entity* pPlayer = this->pPlayerEntity();
    return pPlayer ? pPlayer->pPyEntity() : ScriptObject();
}

/**
 *  This method indicates if this ClientApp can generate movement updates
 *  for this entity.
 */
bool ClientApp::isPlayerMovable() const
{
    BWEntity* pPlayer = pConnection_->pPlayer();

    if (pPlayer == NULL || pPlayer->isDestroyed()) {
        return false;
    }

    return pPlayer->isInWorld() && pPlayer->isControlled() &&
           !pPlayer->isPhysicsCorrected();
}

/**
 *  This method indicates if a Movement Controller
 *  for this entity can be set.
 */
bool ClientApp::canSetMovementController() const
{
    BWEntity* pPlayer = pConnection_->pPlayer();

    if (pPlayer == NULL || pPlayer->isDestroyed()) {
        return false;
    }

    return pPlayer->isInWorld() && pPlayer->isControlled();
}

double ClientApp::clientTime()
{
    return pConnection_->clientTime();
}

double ClientApp::serverTime()
{
    return pConnection_->serverTime();
}

// -----------------------------------------------------------------------------
// Section: Movement controller interface
// -----------------------------------------------------------------------------

/**
 *  This method sets a new default movement controller for this bot.
 */
bool ClientApp::setDefaultMovementController()
{
    if (!this->canSetMovementController()) {
        return false;
    }

    Position3D position = this->position();

    MovementController* pNewController =
      MainApp::instance().createDefaultMovementController(speed_, position);

    this->position(position);

    if (PyErr_Occurred()) {
        return false;
    }

    pMovementController_.reset(pNewController);

    return true;
}

/**
 *  This method sets a new movement controller for this bot. On failure, the
 *  controller is left unchanged.
 *
 *  @return True on success, otherwise false.
 */
bool ClientApp::setMovementController(const BW::string& type,
                                      const BW::string& data)
{
    if (!this->canSetMovementController()) {
        return false;
    }

    Position3D position = this->position();

    MovementController* pNewController =
      MainApp::instance().createMovementController(
        speed_, position, type, data);

    this->position(position);

    if (PyErr_Occurred()) {
        return false;
    }

    pMovementController_.reset(pNewController);

    return true;
}

void ClientApp::moveTo(const Vector3& pos)
{
    if (!this->isPlayerMovable()) {
        // TODO: should add a warning message if we are not in control
        return;
    }

    // make sure no memory leak if called repeatedly from script.
    if (pDest_.get() != NULL) {
        pDest_->set(pos.x, pos.y, pos.z);
    } else {
        pDest_.reset(new Vector3(pos));
    }

    autoMove_ = false;
}

void ClientApp::faceTowards(const Vector3& pos)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    Position3D  position  = this->position();
    Direction3D direction = this->direction();

    direction.yaw = (pos - position).yaw();
    this->updatePosition(position, direction);
}

void ClientApp::stop()
{
    pDest_.reset(NULL);
    autoMove_ = false;
}

// -----------------------------------------------------------------------------
// Section: Direction movement interface
// -----------------------------------------------------------------------------

/**
 *  This method sets the position of the client.
 */
void ClientApp::position(const Position3D& pos)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    Position3D  oldPosition;
    EntityID    vehicleID;
    SpaceID     spaceID;
    Direction3D direction;
    Vector3     oldError;

    BWEntity* pPlayer = pConnection_->pPlayer();

    pPlayer->getLatestMove(
      oldPosition, vehicleID, spaceID, direction, oldError);
    pPlayer->onMoveLocally(pConnection_->clientTime(),
                           pos,
                           vehicleID,
                           /* is2DPosition */ true,
                           direction);
}

/**
 *  This method gets the position of the client.
 */
const Position3D ClientApp::position() const
{
    BWEntity* pPlayer = pConnection_->pPlayer();

    if (pPlayer == NULL || !pPlayer->isInWorld()) {
        static Position3D defaultPos(0, 0, 0);
        return defaultPos;
    }

    return pPlayer->position();
}

/**
 *  This method sets the direction of the client.
 */
void ClientApp::direction(const Direction3D& dir)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    Position3D  position;
    EntityID    vehicleID;
    SpaceID     spaceID;
    Direction3D oldDirection;
    Vector3     error;

    BWEntity* pPlayer = pConnection_->pPlayer();

    pPlayer->getLatestMove(position, vehicleID, spaceID, oldDirection, error);
    // XXX: We lose any error box, onMoveLocally is expected to be accurate.
    pPlayer->onMoveLocally(pConnection_->clientTime(),
                           position,
                           vehicleID,
                           /* is2DPosition */ true,
                           dir);
}

/**
 *  This method gets the direction of the client.
 */
const Direction3D ClientApp::direction() const
{
    BWEntity* pPlayer = pConnection_->pPlayer();

    if (pPlayer == NULL || !pPlayer->isInWorld()) {
        static Direction3D defaultDir(Vector3::zero());
        return defaultDir;
    }

    return pPlayer->direction();
}

/**
 *  This method gets the yaw of the client.
 */
float ClientApp::yaw() const
{
    return this->direction().yaw;
}

/**
 *  This method sets the yaw of the client.
 */
void ClientApp::yaw(float val)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    Position3D  position;
    EntityID    vehicleID;
    SpaceID     spaceID;
    Direction3D direction;
    Vector3     error;

    BWEntity* pPlayer = pConnection_->pPlayer();

    pPlayer->getLatestMove(position, vehicleID, spaceID, direction, error);
    direction.yaw = val;
    // XXX: We lose any error box, onMoveLocally is expected to be accurate.
    pPlayer->onMoveLocally(pConnection_->clientTime(),
                           position,
                           vehicleID,
                           /* is2DPosition */ true,
                           direction);
}

/**
 *  This method gets the pitch of the client.
 */
float ClientApp::pitch() const
{
    return this->direction().pitch;
}

/**
 *  This method sets the pitch of the client.
 */
void ClientApp::pitch(float val)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    Position3D  position;
    EntityID    vehicleID;
    SpaceID     spaceID;
    Direction3D direction;
    Vector3     error;

    BWEntity* pPlayer = pConnection_->pPlayer();

    pPlayer->getLatestMove(position, vehicleID, spaceID, direction, error);
    direction.pitch = val;
    // XXX: We lose any error box, onMoveLocally is expected to be accurate.
    pPlayer->onMoveLocally(pConnection_->clientTime(),
                           position,
                           vehicleID,
                           /* is2DPosition */ true,
                           direction);
}

/**
 *  This method gets the roll of the client.
 */
float ClientApp::roll() const
{
    return this->direction().roll;
}

/**
 *  This method sets the roll of the client.
 */
void ClientApp::roll(float val)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    Position3D  position;
    EntityID    vehicleID;
    SpaceID     spaceID;
    Direction3D direction;
    Vector3     error;

    BWEntity* pPlayer = pConnection_->pPlayer();

    pPlayer->getLatestMove(position, vehicleID, spaceID, direction, error);
    direction.roll = val;
    // XXX: We lose any error box, onMoveLocally is expected to be accurate.
    pPlayer->onMoveLocally(pConnection_->clientTime(),
                           position,
                           vehicleID,
                           /* is2DPosition */ true,
                           direction);
}

/**
 *  This method sets the entity's position and direction.
 */
void ClientApp::updatePosition(const Position3D&  position,
                               const Direction3D& direction)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    BWEntity* pPlayer = pConnection_->pPlayer();

    pPlayer->onMoveLocally(pConnection_->clientTime(),
                           position,
                           NULL_ENTITY_ID,
                           /* is2DPosition */ true,
                           direction);
}

// -----------------------------------------------------------------------------
// Section: Timer interface
// -----------------------------------------------------------------------------

/**
 *  This method adds a timer for this bot.  The callback will be executed during
 *  the next tick after the specified number of seconds has elapsed.  The id of
 *  this timer is returned so it can be cancelled later on with delTimer() if
 *  desired.  A negative return value indicates failure.
 */
int ClientApp::addTimer(float interval, PyObjectPtr pFunc, bool repeat)
{
    if (isDestroyed_) {
        return -1;
    }

    // Make sure a function or method was passed
    if (!PyCallable_Check(pFunc.get())) {
        PyObjectPtr pFuncPyStr(PyObject_Str(pFunc.get()),
                               PyObjectPtr::STEAL_REFERENCE);
        char*       pFuncStr = PyString_AsString(pFuncPyStr.get());

        ERROR_MSG("ClientApp::addTimer(): %s is not callable; "
                  "timer not added\n",
                  pFuncStr);
        return -1;
    }

    // Make new timeRec and insert into the heap of timers
    TimerRec tr(pConnection_->clientTime(), interval, pFunc, repeat);
    timerRecs_.push(tr);
    return tr.id();
}

/**
 *  This method deletes a timer for this bot.  It actually just adds the timer
 *  ID to a list of timers to be ignored so when the timer finally expires its
 *  callback is not executed.
 */
void ClientApp::delTimer(int id)
{
    if (isDestroyed_) {
        return;
    }
    deletedTimerRecs_.push_back(id);
}

// -----------------------------------------------------------------------------
// Section: Private methods
// -----------------------------------------------------------------------------

/**
 *  This method sends a movement message to the server.
 */
void ClientApp::addMove(double dTime)
{
    if (!this->isPlayerMovable()) {
        return;
    }

    Position3D  position  = this->position();
    Direction3D direction = this->direction();

    if (pMovementController_.get() != NULL) {
        pMovementController_->nextStep(speed_, dTime, position, direction);
    } else {
        double      time   = pConnection_->clientTime();
        const float period = 10.f * speed_ / 7.f;
        const float radius = 10.f;
        const float angle  = time * 2 * MATH_PI / period;

        position = Position3D(radius * sinf(angle), 0.f, radius * cosf(angle));

        direction.yaw = angle + MATH_PI / 2.f;
    }

    this->updatePosition(position, direction);
}

// -----------------------------------------------------------------------------
// Section: Timer management
// -----------------------------------------------------------------------------

/**
 *  This method processes any timers that have elapsed
 */
void ClientApp::processTimers()
{
    // Process any timers that have elapsed
    float clientTime = pConnection_->clientTime();
    while (!timerRecs_.empty() && timerRecs_.top().elapsed(clientTime)) {
        TimerRec tr = timerRecs_.top();
        timerRecs_.pop();

        // Check if it has been deleted, if so just ignore it
        BW::list<int>::iterator iter = std::find(
          deletedTimerRecs_.begin(), deletedTimerRecs_.end(), tr.id());
        if (iter != deletedTimerRecs_.end()) {
            deletedTimerRecs_.erase(iter);
            continue;
        }

        PyObject* pResult = PyObject_CallFunction(tr.func(), "");

        if (pResult != NULL) {
            Py_DECREF(pResult);
        } else {
            PyErr_Print();
        }

        // Re-insert the timer into the queue if it's on repeat
        if (tr.repeat()) {
            tr.restart(clientTime);
            timerRecs_.push(tr);
        }
    }
}

// -----------------------------------------------------------------------------
// Section: ServerConnectionHandler overrides
// -----------------------------------------------------------------------------

/**
 *  This method is called when we are logged off from the server.
 */
void ClientApp::onLoggedOff()
{
    EntityID ourID = this->id();

    pMovementController_.reset(NULL);

    // allow script to decide we shall self-destruct or
    // still be alive so that we may reattempt log in.
    ScriptObject module = MainApp::instance().getPersonalityModule();

    if (module && ourID != NULL_ENTITY_ID) {
        ScriptObject func = module.getAttribute(
          "onLoseConnection", ScriptErrorPrint("onLoseConnection"));

        ScriptObject ret;
        if (func) {
            ret = func.callFunction(ScriptArgs::create(ourID),
                                    ScriptErrorPrint("onLoseConnection"));
        }

        if (ret) {
            // if the script returns False, we become dormant
            // otherwise we'll be destroyed after this callback

            isDormant_ = !ret.isTrue(ScriptErrorPrint());
        }
    }

    // Needs to be after we call out to onLoseConnection or the
    // callback code can't find this ClientApp in BigWorld.bots
    pConnection_->clearAllEntities();

    MF_ASSERT(this->id() == NULL_ENTITY_ID);
}

/**
 *  This method is called when we fail to log into the server
 */
void ClientApp::onLogOnFailure(const LogOnStatus& status,
                               const BW::string&  message)
{
    ScriptObject module = MainApp::instance().getPersonalityModule();

    if (module) {
        // Don't remove this line. this is a work around fix for:
        // "two-phase lookup of dependent names in template definitions".
        //  Script::getData( LogOnStatus ) overload for LogOnStatus::Status is
        //  declared earlier in this file by PY_ENUM_CONVERTERS_DECLARE, but
        //  this declaration is after the ScriptArgs::create template
        //  declaration, so ScriptArgs::create() can't see this overloaded
        //  Script::getData() and result into use Script::getData( int ).
        ScriptObject statusValue = ScriptObject(
          Script::getData(status.value()), ScriptObject::FROM_NEW_REFERENCE);

        module.callMethod("onLogOnFailure",
                          ScriptArgs::create(statusValue, userName_),
                          ScriptErrorPrint("BWPersonality.onLogOnFailure"),
                          /* allowNullMethod */ true);
    }

    if (!isZero(BotsConfig::logOnRetryPeriod())) {
        logOnRetryTime_ =
          timestamp() +
          (uint64)(BotsConfig::logOnRetryPeriod() * stampsPerSecond());

        INFO_MSG("ClientApp::onLogOnFailure: %s retry log on in %.2fsecs\n",
                 userName_.c_str(),
                 BotsConfig::logOnRetryPeriod());
    }
}

// -----------------------------------------------------------------------------
// Section: BWEntityFactory overrides
// -----------------------------------------------------------------------------

BWEntity* ClientApp::doCreate(EntityTypeID  entityTypeID,
                              BWConnection* pConnection)
{
    MF_ASSERT(pConnection == pConnection_.get());

    EntityType* pType = EntityType::find(entityTypeID);

    MF_ASSERT(pType != NULL);

    BWEntity* pEntity = NULL;

    if (BotsConfig::shouldUseScripts()) {
        pEntity = new ScriptBotEntity(*this, *pType);
    } else {
        pEntity = new BotEntity(*this, *pType);
    }

    return pEntity;
}

// -----------------------------------------------------------------------------
// Section: BWSpaceDataListener overrides
// -----------------------------------------------------------------------------

/**
 *  This method is called when space data is inserted or deleted for a
 *  user-defined key.
 */
void ClientApp::onUserSpaceData(SpaceID           spaceID,
                                uint16            key,
                                bool              isInsertion,
                                const BW::string& data)
{
    MF_ASSERT(this->id() != NULL_ENTITY_ID);

    ScriptObject module = MainApp::instance().getPersonalityModule();

    if (!module) {
        return;
    }

    const char* pCallbackName =
      isInsertion ? "onSpaceDataCreated" : "onSpaceDataDeleted";

    module.callMethod(pCallbackName,
                      ScriptArgs::create(this->id(), spaceID, key, data),
                      ScriptErrorPrint(pCallbackName),
                      /* allowNullMethod */ true);
}

/**
 *  This method is called when the server adds a space geometry mapping.
 */
void ClientApp::onGeometryMapping(BW::SpaceID       spaceID,
                                  BW::Matrix        matrix,
                                  const BW::string& name)
{
    if (BotsConfig::shouldListenForGeometryMappings()) {
        MainApp::instance().addSpaceGeometryMapping(spaceID, matrix, name);
    }
}

// -----------------------------------------------------------------------------
// Section: BWStreamDataHandler overrides
// -----------------------------------------------------------------------------

/**
 *  Override from ServerMessageHandler, done for testing streaming downloads to
 *  multiple clients.
 */
void ClientApp::onStreamDataComplete(uint16            streamID,
                                     const BW::string& rDescription,
                                     BinaryIStream&    rData)
{
    int len = rData.remainingLength();

    if (len <= 0) {
        ERROR_MSG("ClientApp::onStreamDataComplete: "
                  "Received zero length data\n");
        return;
    }

    int streamSize = rData.remainingLength();

    BW::string data(static_cast<const char*>(rData.retrieve(streamSize)),
                    streamSize);

    this->player().callMethod("onStreamComplete",
                              ScriptArgs::create(streamID, rDescription, data),
                              ScriptErrorPrint(),
                              /* allowNullMethod */ true);
}

// -----------------------------------------------------------------------------
// Section: ClientApp::TimerRec
// -----------------------------------------------------------------------------
int ClientApp::TimerRec::ID_TICKER = 0;

BW_END_NAMESPACE

// client_app.cpp
