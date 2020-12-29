# Automatically generated by pb2py
# fmt: off
from .. import protobuf as p

from .LiskTransactionAsset import LiskTransactionAsset

if __debug__:
    try:
        from typing import Dict, List  # noqa: F401
        from typing_extensions import Literal  # noqa: F401
        EnumTypeLiskTransactionType = Literal[0, 1, 2, 3, 4, 5, 6, 7]
    except ImportError:
        pass


class LiskTransactionCommon(p.MessageType):

    def __init__(
        self,
        *,
        type: EnumTypeLiskTransactionType = None,
        amount: int = None,
        fee: int = None,
        recipient_id: str = None,
        sender_public_key: bytes = None,
        requester_public_key: bytes = None,
        signature: bytes = None,
        timestamp: int = None,
        asset: LiskTransactionAsset = None,
    ) -> None:
        self.type = type
        self.amount = amount
        self.fee = fee
        self.recipient_id = recipient_id
        self.sender_public_key = sender_public_key
        self.requester_public_key = requester_public_key
        self.signature = signature
        self.timestamp = timestamp
        self.asset = asset

    @classmethod
    def get_fields(cls) -> Dict:
        return {
            1: ('type', p.EnumType("LiskTransactionType", (0, 1, 2, 3, 4, 5, 6, 7)), None),
            2: ('amount', p.UVarintType, None),
            3: ('fee', p.UVarintType, None),
            4: ('recipient_id', p.UnicodeType, None),
            5: ('sender_public_key', p.BytesType, None),
            6: ('requester_public_key', p.BytesType, None),
            7: ('signature', p.BytesType, None),
            8: ('timestamp', p.UVarintType, None),
            9: ('asset', LiskTransactionAsset, None),
        }
